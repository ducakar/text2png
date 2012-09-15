/*
 * A simple program to convert text input to a PNG image
 *
 * Written by Davorin Učakar <davorin.ucakar@gmail.com>
 */

#include <QApplication>
#include <QTextCodec>
#include <QPixmap>
#include <QPainter>
#include <QImage>

#include <iostream>
#include <cstdlib>
#include <cstring>

const int WIDTH     = 1024;
const int HEIGHT    = 768;
const int FONT_SIZE = 14;

int main( int argc, char** argv )
{
  QApplication app( argc, argv );
  QTextCodec::setCodecForCStrings( QTextCodec::codecForName( "UTF-8" ) );

  for( const QString s : app.arguments() ) {
    if( s.indexOf( "-" ) != 0 || s == "-?" || s == "-h" || s == "--help" ) {
      std::cout << "Usage: " << app.argv()[0] << std::endl
                << "  Input text is read from stdin and written to `out.png'." << std::endl
                << "  Colours are given as hexadecimal values (like in HTML/CSS)." << std::endl;

      return EXIT_FAILURE;
    }
  }

  QPixmap  pixmap( WIDTH, HEIGHT );
  QFont    font( "LucidaTypewriter" );
  QPoint   point( 0, FONT_SIZE );
  QPainter painter( &pixmap );

  pixmap.fill( Qt::black );
  font.setBold( true );
  font.setPixelSize( FONT_SIZE );
  painter.setPen( Qt::green );
  painter.setFont( font );

  char line[128];
  while( fgets( line, 128, stdin ) != 0 ) {
    size_t len = strlen( line );

    if( len > 0 && line[len - 1] == '\n' ) {
      line[len - 1] = '\0';
    }

    painter.drawText( point, line );
    point.ry() += 16;
  }

  QImage image = pixmap.toImage();

  int maxX = 0;
  int maxY = 0;

  for( int x = 0; x < WIDTH; ++x ) {
    for( int y = 0; y < HEIGHT; ++y ) {
      if( image.pixel( x, y ) & 0x00ffffff ) {
        maxX = x > maxX ? x : maxX;
        maxY = y > maxY ? y : maxY;
      }
    }
  }

  QPixmap  croppedPixmap( maxX + 21, maxY + 11 );
  QPainter croppedPainter( &croppedPixmap );

  croppedPixmap.fill( Qt::black );
  croppedPainter.drawPixmap( 10, 0, pixmap, 0, 0, maxX + 1, maxY + 1 );
  croppedPixmap.save( "out.png" );

  return EXIT_SUCCESS;
}

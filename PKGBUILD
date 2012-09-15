# Maintainer: Davorin Učakar <davorin.ucakar@gmail.com>

pkgname=text2png
pkgver=0.1
pkgrel=1
pkgdesc='Simple program to convert text input to a PNG image'
url='http://github.com/ducakar/text2png/'
arch=('i686' 'x86_64')
license=('Public Domain')
depends=('qt')
source=('text2png.tar.gz')
sha1sums=('')

build() {
  cd "${srcdir}"

  mkdir build && cd build
  cmake ../${pkgname} \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=/usr
  make
}

package() {
  cd "${srcdir}"/build

  make DESTDIR="${pkgdir}" install
}

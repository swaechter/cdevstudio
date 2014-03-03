#! /bin/bash

# Defines
email=waechter.simon@gmail.com
version=0.0.7

# Create orig.tar.gz archive
tar -czf cdevstudio_${version}.orig.tar.gz ../../../cdevstudio
tar -xf cdevstudio_${version}.orig.tar.gz

# Rename directory
mv cdevstudio cdevstudio-${version}

# Prepare for debuild
cp -R debian cdevstudio-${version}
cd cdevstudio-${version}

# Create package
dh_make -s -e ${email} -f ../cdevstudio_${version}.orig.tar.gz
debuild -us -uc

# Cleanup
cd ..
rm -rf cdevstudio
rm -rf cdevstudio-${version}
rm *.dsc
rm *.tar.gz
rm *.tar.xz
rm *.build
rm *.changes

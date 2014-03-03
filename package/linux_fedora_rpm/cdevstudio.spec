Summary             : A C/C++ IDE
Name                : cdevstudio
Version             : 0.0.7
Release             : 7
License             : GPLv3
Source              : %{name}-%{version}.tar.gz

%description
A C/C++ IDE for Unix, Linux, OS X and Windows.

%prep
%setup

%build
%cmake ../%{name}-%{version} -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr
make

%install
make install DESTDIR="%{buildroot}"

%files
/usr/bin/cdevstudio
/usr/share/applications/cdevstudio.desktop
/usr/share/man/man1/cdevstudio.1.gz
/usr/lib/libcdevstudioplatform.so*
/usr/include/cdevstudioplatform/CDevStudioPlatformExport.h
/usr/include/cdevstudioplatform/CDevStudioPlatform.h
/usr/include/cdevstudioplatform/CDevStudioProject.h
/usr/include/cdevstudioplatform/CDevStudioProjectTemplate.h
/usr/include/cdevstudioplatform/CDevStudioWindow.h
/usr/include/cdevstudioplatform/CDevStudioBackend.h
/usr/include/cdevstudioplatform/ICDevStudioPlugin.h
/usr/lib/libpluginhelp.so*
/usr/lib/libpluginprojects.so*

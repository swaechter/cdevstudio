Summary             : A C/C++ IDE
Name                : cdevstudio
Version             : 0.0.4
Release             : 1
License             : GPLv3
Source              : %{name}-%{version}.tar.gz

%description
A C/C++ IDE for Unix, Linux, OS X and Windows.

%prep
%setup

%build
%cmake ../%{name}-%{version} -DCMAKE_BUILD_TYPE=Release
make

%install
make install DESTDIR="%{buildroot}"

%files
/usr/bin/cdevstudio
/usr/lib/libcdevstudiocodeedit.so
/usr/lib/libcdevstudiocodeedit.so.0
/usr/lib/libcdevstudiocodeedit.so.0.0.1
/usr/lib/libcdevstudioplatform.so
/usr/lib/libcdevstudioplatform.so.0
/usr/lib/libcdevstudioplatform.so.0.0.1
/usr/lib/libcdevstudiobackend.so
/usr/lib/libcdevstudiobackend.so.0
/usr/lib/libcdevstudiobackend.so.0.0.1
/usr/include/CDevStudioCodeEdit.h
/usr/include/CDevStudioCodeEditExport.h
/usr/include/CDevStudioPlatform.h
/usr/include/CDevStudioPlatformExport.h
/usr/include/CDevStudioProject.h
/usr/include/CDevStudioBackend.h
/usr/include/CDevStudioBackendExport.h
/usr/share/applications/cdevstudio.desktop
/usr/share/man/man1/cdevstudio.1.gz
/usr/share/cdevstudio/translation_en.qm
/usr/share/cdevstudio/translation_de.qm

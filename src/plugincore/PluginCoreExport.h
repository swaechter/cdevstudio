#ifndef PLUGINCOREEXPORT_H
#define PLUGINCOREEXPORT_H

#ifdef PLUGINCORE_MAKE_LIBRARY
	#define PLUGINCORE_EXPORT Q_DECL_EXPORT
#else
	#define PLUGINCORE_EXPORT Q_DECL_IMPORT
#endif

#endif // PLUGINCOREEXPORT_H
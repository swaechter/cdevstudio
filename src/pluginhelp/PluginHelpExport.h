#ifndef PLUGINHELPEXPORT_H
#define PLUGINHELPEXPORT_H

#ifdef PLUGINHELP_MAKE_LIBRARY
	#define PLUGINHELP_EXPORT Q_DECL_EXPORT
#else
	#define PLUGINHELP_EXPORT Q_DECL_IMPORT
#endif

#endif // PLUGINHELPEXPORT_H
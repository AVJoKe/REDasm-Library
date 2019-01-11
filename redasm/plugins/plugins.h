#ifndef PLUGINS_H
#define PLUGINS_H

#include <unordered_map>
#include <string>
#include <list>
#include "format.h"
#include "assembler/assembler.h"

namespace REDasm {

template<typename T> struct EntryListT { typedef std::list<T> Type; };
template<typename T> struct EntryMapT { typedef std::unordered_map<std::string, T> Type; };

template<typename T> typename EntryMapT<T>::Type::const_iterator findPluginEntry(const char* id, const typename EntryMapT<T>::Type& pm)
{
    if(!id)
        return pm.end();

    return pm.find(id);
}

struct Plugins
{
    static LIBREDASM_EXPORT EntryListT<FormatPlugin_Entry>::Type formats;
    static LIBREDASM_EXPORT EntryMapT<AssemblerPlugin_Entry>::Type assemblers;
};

FormatPlugin* getFormat(Buffer &buffer);
AssemblerPlugin* getAssembler(const char* id);
void setLoggerCallback(Runtime::LogCallback logcb);
void setStatusCallback(Runtime::LogCallback logcb);
void setProgressCallback(Runtime::ProgressCallback pcb);
void init(const std::string &temppath = std::string(), const std::string &searchpath = std::string());

}

#endif // PLUGINS_H

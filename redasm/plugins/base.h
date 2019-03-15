#ifndef BASE_H
#define BASE_H

#include <functional>
#include "../redasm.h"

#define PLUGIN_NAME(pluginname) public: \
                                static constexpr const char* Name = pluginname; \
                                virtual std::string name() const { return pluginname; } \
                                private:

#define PLUGIN_INHERIT(classname, basename, name, ctor, args) class classname: public UNPAREN(basename) { \
                                                           PLUGIN_NAME(name) \
                                                           public: classname(ctor): UNPAREN(basename)(args) { } \
                                                       };

namespace REDasm {

class Plugin
{
    public:
        Plugin() { }
        virtual ~Plugin() { }
        virtual std::string name() const = 0;
        std::string id() const { return m_id; }
        void setId(const std::string& id) { m_id = id; }

    private:
        std::string m_id;
};

}

#endif // BASE_H

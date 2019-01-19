#ifndef XBE_H
#define XBE_H

// Documentation: www.caustik.com/cxbx/download/xbe.htm

#include "../../plugins/plugins.h"
#include "xbe_header.h"

namespace REDasm {

class XbeFormat : public FormatPluginT<XbeImageHeader>
{
    DEFINE_FORMAT_PLUGIN_TEST(XbeImageHeader)

    public:
        XbeFormat(Buffer& buffer);
        virtual std::string name() const;
        virtual std::string assembler() const;
        virtual u32 bits() const;
        virtual void load();

    private:
        void displayXbeInfo();
        bool decodeEP(u32 encodedep, address_t &ep);
        bool decodeKernel(u32 encodedthunk, u32 &thunk);
        void loadSections(XbeSectionHeader* sectionhdr);
        bool loadXBoxKrnl();

    private:
        template<typename T> T* memoryoffset(u32 memaddress) const;
};

template<typename T> T* XbeFormat::memoryoffset(u32 memaddress) const { return this->pointer<T>(memaddress - this->m_format->BaseAddress); }

DECLARE_FORMAT_PLUGIN(XbeFormat, xbe)

} // namespace REDasm

#endif // XBE_H

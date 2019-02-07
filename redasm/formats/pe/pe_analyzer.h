#ifndef PE_ANALYZER_H
#define PE_ANALYZER_H

#include "../../analyzer/analyzer.h"
#include <forward_list>

namespace REDasm {

class PEAnalyzer: public Analyzer
{
    private:
        typedef std::pair<size_t, std::string> APIInfo;

    public:
        PEAnalyzer(DisassemblerAPI* disassembler, const SignatureFiles &signatures);
        virtual void analyze();

    private:
        SymbolPtr getImport(const std::string& library, const std::string& api);
        ReferenceVector getAPIReferences(const std::string& library, const std::string& api);
        void findWndProc(address_t address, size_t argidx);
        void findCRTWinMain();
        void findAllWndProc();

    private:
        std::forward_list<APIInfo> m_wndprocapi;
};

}

#endif // PE_ANALYZER_H

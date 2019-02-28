#ifndef DALVIK_PRINTER_H
#define DALVIK_PRINTER_H

#include "../../plugins/assembler/printer.h"
#include "../../formats/dex/dex_header.h"

namespace REDasm {

class DEXFormat;

class DalvikPrinter : public Printer
{
    public:
        DalvikPrinter(DisassemblerAPI* disassembler);
        virtual void function(const Symbol* symbol, const FunctionCallback &plgfunc);
        virtual void prologue(const Symbol* symbol, const LineCallback& prologuefunc);
        virtual void info(const InstructionPtr &instruction, const LineCallback& infofunc);
        virtual std::string reg(const RegisterOperand &regop) const;
        virtual std::string imm(const Operand *op) const;

    private:
        static std::string registerName(register_id_t r);
        void startLocal(REDasm::DEXFormat *dexformat, const DEXDebugData& debugdata);
        void restoreLocal(REDasm::DEXFormat *dexformat, register_id_t r);
        void endLocal(register_id_t r);

    private:
        DEXDebugInfo m_currentdbginfo;
        std::unordered_map<register_id_t, DEXDebugData> m_regoverrides;
        std::unordered_map<register_id_t, std::string> m_regnames;
};

} // namespace REDasm

#endif // DALVIK_PRINTER_H

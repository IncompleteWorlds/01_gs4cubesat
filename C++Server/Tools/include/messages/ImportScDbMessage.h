/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */
 
#ifndef __IMPORT_SC_DB_MESSAGE__
#define __IMPORT_SC_DB_MESSAGE__

// Reading Excel spreadsheet
#include "BasicExcel.hpp"
#include "ExcelFormat.h"

#include "BaseMessage.h"

// It imports the S/C Database from an Excel file, a CSV file or an XTCE file (TBD)
// If there is an error, it will return MsgReturnData with the error code
class ImportScDbMessage : public BaseMessage
{
    public:
        ImportScDbMessage();
        virtual ~ImportScDbMessage();

        ServerMessage processMessage(const ServerMessage &inMessage, ServerWorker& inParent);

    protected:
        void processExcel(IW::MsgImportScDatabase  &inMessage, ServerMessage &outMessage);
        
        void processCsv(IW::MsgImportScDatabase  &inMessage, ServerMessage &outMessage);
        
        void processXtce(IW::MsgImportScDatabase  &inMessage, ServerMessage &outMessage);
        
        void extractTmParameter(shared_ptr<ExcelFormat::BasicExcelWorksheet> &inTab, uint inRowIndex, IW::TM_Parameter &outParameter);
};

#endif // __IMPORT_SC_DB_MESSAGE__

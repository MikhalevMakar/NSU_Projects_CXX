// Created by Макар Михалёв on 06.12.2022.
//

#include "ServiceMuteAndWAV.h"

void  ServiceMuteAndWAV::firstLaunchConvertorAndWAV(ParseCommandLine* ptrParseCommandLine,
                                                    Convertor* ptrConvertor,
                                                    std::vector<std::string> vectorInputFile,
                                                    ConfigurationFile* ptrConfigurationFile,
                                                    WAV* ptrWAV) {
    ptrConvertor->readArg(ptrConfigurationFile);
    tmpCnt = ptrConvertor->getBeginningTime();
    ptrWAV->fileOverWritten(tmpCnt, bufferSample1);

    while(ptrWAV->readNewSample(bufferSample1)) {
        if (++tmpCnt > ptrConvertor->getEndingTime()) break;
        ptrConvertor->changingSamples(bufferSample1,
                                      bufferSample2);
        ptrWAV->writeSample(bufferSample1);
    }
    ptrWAV->writeLastPart(bufferSample1);
}

void ServiceMuteAndWAV::linkConvertorAndWAV(ParseCommandLine* ptrParseCommandLine,
                                            Convertor* ptrConvertor,
                                            std::vector<std::string> vectorInputFile,
                                            ConfigurationFile* ptrConfigurationFile,
                                            WAV* ptrWAV)  {

    ptrConvertor->readArg(ptrConfigurationFile);
    tmpCnt = ptrConvertor->getBeginningTime();
    ptrWAV->seekIntroFile(tmpCnt);

    while(ptrWAV->readNewSample(bufferSample1)) {
        if(++tmpCnt > ptrConvertor->getEndingTime()) break;
        ptrConvertor->changingSamples(bufferSample1,
                                      bufferSample2);
        ptrWAV->imageOverwrite(bufferSample1);
    }
}


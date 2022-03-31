##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Common
ConfigurationName      :=Debug
WorkspacePath          :=/home/alberto/Projects/01_gs4cubesat/C++Server
ProjectPath            :=/home/alberto/Projects/01_gs4cubesat/C++Server/Common
IntermediateDirectory  :=./obj/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=alberto
Date                   :=20/03/21
CodeLitePath           :=/home/alberto/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=./bin/Debug/lib$(ProjectName).so
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="Common.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)zmq $(LibrarySwitch)log4cpp $(LibrarySwitch)avrocpp 
ArLibs                 :=  "zmq" "log4cpp" "avrocpp" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/local/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -std=c++11 -Wall -fexceptions  -fPIC $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_ConfigurationManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ServerWorkerZmq.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ServerWorkerNng.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ServerWorkerSubZmq.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_json11.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ServerMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Crc.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_MessageUtils.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_TimeUtils.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_CommonUtils.cpp$(ObjectSuffix) \
	

Objects1=$(IntermediateDirectory)/src_ServerWorkerTransferNng.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_LogManager.cpp$(ObjectSuffix) 



Objects=$(Objects0) $(Objects1) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	@echo $(Objects1) >> $(ObjectsFileList)
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)
	@$(MakeDirCommand) "/home/alberto/Projects/01_gs4cubesat/C++Server/.build-debug"
	@echo rebuilt > "/home/alberto/Projects/01_gs4cubesat/C++Server/.build-debug/Common"

MakeIntermediateDirs:
	@test -d ./obj/Debug || $(MakeDirCommand) ./obj/Debug


$(IntermediateDirectory)/.d:
	@test -d ./obj/Debug || $(MakeDirCommand) ./obj/Debug

PreBuild:
	@echo Executing Pre Build commands ...
	cd ./resources;  ./compile.sh
	@echo Done


##
## Objects
##
$(IntermediateDirectory)/src_ConfigurationManager.cpp$(ObjectSuffix): src/ConfigurationManager.cpp $(IntermediateDirectory)/src_ConfigurationManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Common/src/ConfigurationManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ConfigurationManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ConfigurationManager.cpp$(DependSuffix): src/ConfigurationManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ConfigurationManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ConfigurationManager.cpp$(DependSuffix) -MM src/ConfigurationManager.cpp

$(IntermediateDirectory)/src_ConfigurationManager.cpp$(PreprocessSuffix): src/ConfigurationManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ConfigurationManager.cpp$(PreprocessSuffix) src/ConfigurationManager.cpp

$(IntermediateDirectory)/src_ServerWorkerZmq.cpp$(ObjectSuffix): src/ServerWorkerZmq.cpp $(IntermediateDirectory)/src_ServerWorkerZmq.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Common/src/ServerWorkerZmq.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ServerWorkerZmq.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ServerWorkerZmq.cpp$(DependSuffix): src/ServerWorkerZmq.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ServerWorkerZmq.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ServerWorkerZmq.cpp$(DependSuffix) -MM src/ServerWorkerZmq.cpp

$(IntermediateDirectory)/src_ServerWorkerZmq.cpp$(PreprocessSuffix): src/ServerWorkerZmq.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ServerWorkerZmq.cpp$(PreprocessSuffix) src/ServerWorkerZmq.cpp

$(IntermediateDirectory)/src_ServerWorkerNng.cpp$(ObjectSuffix): src/ServerWorkerNng.cpp $(IntermediateDirectory)/src_ServerWorkerNng.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Common/src/ServerWorkerNng.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ServerWorkerNng.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ServerWorkerNng.cpp$(DependSuffix): src/ServerWorkerNng.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ServerWorkerNng.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ServerWorkerNng.cpp$(DependSuffix) -MM src/ServerWorkerNng.cpp

$(IntermediateDirectory)/src_ServerWorkerNng.cpp$(PreprocessSuffix): src/ServerWorkerNng.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ServerWorkerNng.cpp$(PreprocessSuffix) src/ServerWorkerNng.cpp

$(IntermediateDirectory)/src_ServerWorkerSubZmq.cpp$(ObjectSuffix): src/ServerWorkerSubZmq.cpp $(IntermediateDirectory)/src_ServerWorkerSubZmq.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Common/src/ServerWorkerSubZmq.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ServerWorkerSubZmq.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ServerWorkerSubZmq.cpp$(DependSuffix): src/ServerWorkerSubZmq.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ServerWorkerSubZmq.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ServerWorkerSubZmq.cpp$(DependSuffix) -MM src/ServerWorkerSubZmq.cpp

$(IntermediateDirectory)/src_ServerWorkerSubZmq.cpp$(PreprocessSuffix): src/ServerWorkerSubZmq.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ServerWorkerSubZmq.cpp$(PreprocessSuffix) src/ServerWorkerSubZmq.cpp

$(IntermediateDirectory)/src_json11.cpp$(ObjectSuffix): src/json11.cpp $(IntermediateDirectory)/src_json11.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Common/src/json11.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_json11.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_json11.cpp$(DependSuffix): src/json11.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_json11.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_json11.cpp$(DependSuffix) -MM src/json11.cpp

$(IntermediateDirectory)/src_json11.cpp$(PreprocessSuffix): src/json11.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_json11.cpp$(PreprocessSuffix) src/json11.cpp

$(IntermediateDirectory)/src_ServerMessage.cpp$(ObjectSuffix): src/ServerMessage.cpp $(IntermediateDirectory)/src_ServerMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Common/src/ServerMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ServerMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ServerMessage.cpp$(DependSuffix): src/ServerMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ServerMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ServerMessage.cpp$(DependSuffix) -MM src/ServerMessage.cpp

$(IntermediateDirectory)/src_ServerMessage.cpp$(PreprocessSuffix): src/ServerMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ServerMessage.cpp$(PreprocessSuffix) src/ServerMessage.cpp

$(IntermediateDirectory)/src_Crc.cpp$(ObjectSuffix): src/Crc.cpp $(IntermediateDirectory)/src_Crc.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Common/src/Crc.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Crc.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Crc.cpp$(DependSuffix): src/Crc.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Crc.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Crc.cpp$(DependSuffix) -MM src/Crc.cpp

$(IntermediateDirectory)/src_Crc.cpp$(PreprocessSuffix): src/Crc.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Crc.cpp$(PreprocessSuffix) src/Crc.cpp

$(IntermediateDirectory)/src_MessageUtils.cpp$(ObjectSuffix): src/MessageUtils.cpp $(IntermediateDirectory)/src_MessageUtils.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Common/src/MessageUtils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_MessageUtils.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_MessageUtils.cpp$(DependSuffix): src/MessageUtils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_MessageUtils.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_MessageUtils.cpp$(DependSuffix) -MM src/MessageUtils.cpp

$(IntermediateDirectory)/src_MessageUtils.cpp$(PreprocessSuffix): src/MessageUtils.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_MessageUtils.cpp$(PreprocessSuffix) src/MessageUtils.cpp

$(IntermediateDirectory)/src_TimeUtils.cpp$(ObjectSuffix): src/TimeUtils.cpp $(IntermediateDirectory)/src_TimeUtils.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Common/src/TimeUtils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_TimeUtils.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_TimeUtils.cpp$(DependSuffix): src/TimeUtils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_TimeUtils.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_TimeUtils.cpp$(DependSuffix) -MM src/TimeUtils.cpp

$(IntermediateDirectory)/src_TimeUtils.cpp$(PreprocessSuffix): src/TimeUtils.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_TimeUtils.cpp$(PreprocessSuffix) src/TimeUtils.cpp

$(IntermediateDirectory)/src_CommonUtils.cpp$(ObjectSuffix): src/CommonUtils.cpp $(IntermediateDirectory)/src_CommonUtils.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Common/src/CommonUtils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_CommonUtils.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_CommonUtils.cpp$(DependSuffix): src/CommonUtils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_CommonUtils.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_CommonUtils.cpp$(DependSuffix) -MM src/CommonUtils.cpp

$(IntermediateDirectory)/src_CommonUtils.cpp$(PreprocessSuffix): src/CommonUtils.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_CommonUtils.cpp$(PreprocessSuffix) src/CommonUtils.cpp

$(IntermediateDirectory)/src_ServerWorkerTransferNng.cpp$(ObjectSuffix): src/ServerWorkerTransferNng.cpp $(IntermediateDirectory)/src_ServerWorkerTransferNng.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Common/src/ServerWorkerTransferNng.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ServerWorkerTransferNng.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ServerWorkerTransferNng.cpp$(DependSuffix): src/ServerWorkerTransferNng.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ServerWorkerTransferNng.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ServerWorkerTransferNng.cpp$(DependSuffix) -MM src/ServerWorkerTransferNng.cpp

$(IntermediateDirectory)/src_ServerWorkerTransferNng.cpp$(PreprocessSuffix): src/ServerWorkerTransferNng.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ServerWorkerTransferNng.cpp$(PreprocessSuffix) src/ServerWorkerTransferNng.cpp

$(IntermediateDirectory)/src_LogManager.cpp$(ObjectSuffix): src/LogManager.cpp $(IntermediateDirectory)/src_LogManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Common/src/LogManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LogManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LogManager.cpp$(DependSuffix): src/LogManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_LogManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_LogManager.cpp$(DependSuffix) -MM src/LogManager.cpp

$(IntermediateDirectory)/src_LogManager.cpp$(PreprocessSuffix): src/LogManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LogManager.cpp$(PreprocessSuffix) src/LogManager.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./obj/Debug/



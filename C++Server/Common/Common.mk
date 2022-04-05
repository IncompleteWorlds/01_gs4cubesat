##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Common
ConfigurationName      :=Debug
WorkspacePath          :=/mnt/windows/Documents/01_gs4cubesat
ProjectPath            :=/mnt/windows/Documents/01_gs4cubesat/C++Server/Common
IntermediateDirectory  :=./obj/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alberto
Date                   :=09/05/19
CodeLitePath           :=/home/alberto/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
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
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -std=c++11 -Wall -fexceptions -m64 -fPIC $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_Crc.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_LogManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_TimeUtils.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ConfigurationManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_json11.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ServerMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_CommonUtils.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ServerWorkerSub.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_MessageUtils.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ServerWorker.cpp$(ObjectSuffix) \
	



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)
	@$(MakeDirCommand) "/mnt/windows/Documents/01_gs4cubesat/.build-debug"
	@echo rebuilt > "/mnt/windows/Documents/01_gs4cubesat/.build-debug/Common"

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
$(IntermediateDirectory)/src_Crc.cpp$(ObjectSuffix): src/Crc.cpp $(IntermediateDirectory)/src_Crc.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/windows/Documents/01_gs4cubesat/C++Server/Common/src/Crc.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Crc.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Crc.cpp$(DependSuffix): src/Crc.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Crc.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Crc.cpp$(DependSuffix) -MM src/Crc.cpp

$(IntermediateDirectory)/src_Crc.cpp$(PreprocessSuffix): src/Crc.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Crc.cpp$(PreprocessSuffix) src/Crc.cpp

$(IntermediateDirectory)/src_LogManager.cpp$(ObjectSuffix): src/LogManager.cpp $(IntermediateDirectory)/src_LogManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/windows/Documents/01_gs4cubesat/C++Server/Common/src/LogManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LogManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LogManager.cpp$(DependSuffix): src/LogManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_LogManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_LogManager.cpp$(DependSuffix) -MM src/LogManager.cpp

$(IntermediateDirectory)/src_LogManager.cpp$(PreprocessSuffix): src/LogManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LogManager.cpp$(PreprocessSuffix) src/LogManager.cpp

$(IntermediateDirectory)/src_TimeUtils.cpp$(ObjectSuffix): src/TimeUtils.cpp $(IntermediateDirectory)/src_TimeUtils.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/windows/Documents/01_gs4cubesat/C++Server/Common/src/TimeUtils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_TimeUtils.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_TimeUtils.cpp$(DependSuffix): src/TimeUtils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_TimeUtils.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_TimeUtils.cpp$(DependSuffix) -MM src/TimeUtils.cpp

$(IntermediateDirectory)/src_TimeUtils.cpp$(PreprocessSuffix): src/TimeUtils.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_TimeUtils.cpp$(PreprocessSuffix) src/TimeUtils.cpp

$(IntermediateDirectory)/src_ConfigurationManager.cpp$(ObjectSuffix): src/ConfigurationManager.cpp $(IntermediateDirectory)/src_ConfigurationManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/windows/Documents/01_gs4cubesat/C++Server/Common/src/ConfigurationManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ConfigurationManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ConfigurationManager.cpp$(DependSuffix): src/ConfigurationManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ConfigurationManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ConfigurationManager.cpp$(DependSuffix) -MM src/ConfigurationManager.cpp

$(IntermediateDirectory)/src_ConfigurationManager.cpp$(PreprocessSuffix): src/ConfigurationManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ConfigurationManager.cpp$(PreprocessSuffix) src/ConfigurationManager.cpp

$(IntermediateDirectory)/src_json11.cpp$(ObjectSuffix): src/json11.cpp $(IntermediateDirectory)/src_json11.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/windows/Documents/01_gs4cubesat/C++Server/Common/src/json11.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_json11.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_json11.cpp$(DependSuffix): src/json11.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_json11.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_json11.cpp$(DependSuffix) -MM src/json11.cpp

$(IntermediateDirectory)/src_json11.cpp$(PreprocessSuffix): src/json11.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_json11.cpp$(PreprocessSuffix) src/json11.cpp

$(IntermediateDirectory)/src_ServerMessage.cpp$(ObjectSuffix): src/ServerMessage.cpp $(IntermediateDirectory)/src_ServerMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/windows/Documents/01_gs4cubesat/C++Server/Common/src/ServerMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ServerMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ServerMessage.cpp$(DependSuffix): src/ServerMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ServerMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ServerMessage.cpp$(DependSuffix) -MM src/ServerMessage.cpp

$(IntermediateDirectory)/src_ServerMessage.cpp$(PreprocessSuffix): src/ServerMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ServerMessage.cpp$(PreprocessSuffix) src/ServerMessage.cpp

$(IntermediateDirectory)/src_CommonUtils.cpp$(ObjectSuffix): src/CommonUtils.cpp $(IntermediateDirectory)/src_CommonUtils.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/windows/Documents/01_gs4cubesat/C++Server/Common/src/CommonUtils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_CommonUtils.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_CommonUtils.cpp$(DependSuffix): src/CommonUtils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_CommonUtils.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_CommonUtils.cpp$(DependSuffix) -MM src/CommonUtils.cpp

$(IntermediateDirectory)/src_CommonUtils.cpp$(PreprocessSuffix): src/CommonUtils.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_CommonUtils.cpp$(PreprocessSuffix) src/CommonUtils.cpp

$(IntermediateDirectory)/src_ServerWorkerSub.cpp$(ObjectSuffix): src/ServerWorkerSub.cpp $(IntermediateDirectory)/src_ServerWorkerSub.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/windows/Documents/01_gs4cubesat/C++Server/Common/src/ServerWorkerSub.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ServerWorkerSub.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ServerWorkerSub.cpp$(DependSuffix): src/ServerWorkerSub.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ServerWorkerSub.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ServerWorkerSub.cpp$(DependSuffix) -MM src/ServerWorkerSub.cpp

$(IntermediateDirectory)/src_ServerWorkerSub.cpp$(PreprocessSuffix): src/ServerWorkerSub.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ServerWorkerSub.cpp$(PreprocessSuffix) src/ServerWorkerSub.cpp

$(IntermediateDirectory)/src_MessageUtils.cpp$(ObjectSuffix): src/MessageUtils.cpp $(IntermediateDirectory)/src_MessageUtils.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/windows/Documents/01_gs4cubesat/C++Server/Common/src/MessageUtils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_MessageUtils.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_MessageUtils.cpp$(DependSuffix): src/MessageUtils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_MessageUtils.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_MessageUtils.cpp$(DependSuffix) -MM src/MessageUtils.cpp

$(IntermediateDirectory)/src_MessageUtils.cpp$(PreprocessSuffix): src/MessageUtils.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_MessageUtils.cpp$(PreprocessSuffix) src/MessageUtils.cpp

$(IntermediateDirectory)/src_ServerWorker.cpp$(ObjectSuffix): src/ServerWorker.cpp $(IntermediateDirectory)/src_ServerWorker.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/windows/Documents/01_gs4cubesat/C++Server/Common/src/ServerWorker.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ServerWorker.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ServerWorker.cpp$(DependSuffix): src/ServerWorker.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ServerWorker.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ServerWorker.cpp$(DependSuffix) -MM src/ServerWorker.cpp

$(IntermediateDirectory)/src_ServerWorker.cpp$(PreprocessSuffix): src/ServerWorker.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ServerWorker.cpp$(PreprocessSuffix) src/ServerWorker.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./obj/Debug/



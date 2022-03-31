##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=HKTM_Processor
ConfigurationName      :=Debug
WorkspacePath          :=/home/alberto/Projects/01_gs4cubesat/C++Server
ProjectPath            :=/home/alberto/Projects/01_gs4cubesat/C++Server/HKTM_Processor
IntermediateDirectory  :=./obj/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alberto
Date                   :=11/11/19
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
OutputFile             :=./bin/Debug/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="HKTM_Processor.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./include $(IncludeSwitch)../Common/include $(IncludeSwitch)../Security/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)Common $(LibrarySwitch)Security_Access_Control $(LibrarySwitch)avrocpp $(LibrarySwitch)zmq $(LibrarySwitch)pthread $(LibrarySwitch)boost_system $(LibrarySwitch)SQLiteCpp $(LibrarySwitch)sqlite3 $(LibrarySwitch)log4cpp 
ArLibs                 :=  "Common" "Security_Access_Control" "avrocpp" "zmq" "pthread" "boost_system" "SQLiteCpp" "sqlite3" "log4cpp" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/local/lib $(LibraryPathSwitch)../Common/bin/Debug $(LibraryPathSwitch)../Security_Access_Control/bin/Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall -std=c++11 -fexceptions -m64 -Weffc++ $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
LD_LIBRARY_PATH:=$LD_LIBRARY_PATH:/home/alberto/Projects/01_gs4cubesat/C++Server/C++Server/Common/bin/Debug:/home/alberto/Projects/01_gs4cubesat/C++Server/C++Server/Security_Access_Control/bin/Debug
Objects0=$(IntermediateDirectory)/src_HkTmProcessorMessageProcessor.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_NewRawFrameMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_tm_processor_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_HkTmProcessorModuleManager.cpp$(ObjectSuffix) 



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
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./obj/Debug || $(MakeDirCommand) ./obj/Debug


$(IntermediateDirectory)/.d:
	@test -d ./obj/Debug || $(MakeDirCommand) ./obj/Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_HkTmProcessorMessageProcessor.cpp$(ObjectSuffix): src/HkTmProcessorMessageProcessor.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/HKTM_Processor/src/HkTmProcessorMessageProcessor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_HkTmProcessorMessageProcessor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_HkTmProcessorMessageProcessor.cpp$(PreprocessSuffix): src/HkTmProcessorMessageProcessor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_HkTmProcessorMessageProcessor.cpp$(PreprocessSuffix) src/HkTmProcessorMessageProcessor.cpp

$(IntermediateDirectory)/src_messages_NewRawFrameMessage.cpp$(ObjectSuffix): src/messages/NewRawFrameMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/HKTM_Processor/src/messages/NewRawFrameMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_NewRawFrameMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_NewRawFrameMessage.cpp$(PreprocessSuffix): src/messages/NewRawFrameMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_NewRawFrameMessage.cpp$(PreprocessSuffix) src/messages/NewRawFrameMessage.cpp

$(IntermediateDirectory)/src_tm_processor_main.cpp$(ObjectSuffix): src/tm_processor_main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/HKTM_Processor/src/tm_processor_main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_tm_processor_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_tm_processor_main.cpp$(PreprocessSuffix): src/tm_processor_main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_tm_processor_main.cpp$(PreprocessSuffix) src/tm_processor_main.cpp

$(IntermediateDirectory)/src_HkTmProcessorModuleManager.cpp$(ObjectSuffix): src/HkTmProcessorModuleManager.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/HKTM_Processor/src/HkTmProcessorModuleManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_HkTmProcessorModuleManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_HkTmProcessorModuleManager.cpp$(PreprocessSuffix): src/HkTmProcessorModuleManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_HkTmProcessorModuleManager.cpp$(PreprocessSuffix) src/HkTmProcessorModuleManager.cpp

##
## Clean
##
clean:
	$(RM) -r ./obj/Debug/



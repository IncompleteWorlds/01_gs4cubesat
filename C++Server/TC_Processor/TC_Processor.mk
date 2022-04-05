##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=TC_Processor
ConfigurationName      :=Release
WorkspacePath          :=/home/alberto/Documents/01_gs4cubesat
ProjectPath            :=/home/alberto/Documents/01_gs4cubesat/C++Server/TC_Processor
IntermediateDirectory  :=./obj/Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alberto
Date                   :=03/05/18
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
OutputFile             :=./bin/Release/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="TC_Processor.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)include $(IncludeSwitch)../Common/include $(IncludeSwitch)../Security_Access_Control/include $(IncludeSwitch)../Common/include/clients 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)Security_Access_Control $(LibrarySwitch)Common $(LibrarySwitch)pthread $(LibrarySwitch)avrocpp $(LibrarySwitch)zmq $(LibrarySwitch)boost_system $(LibrarySwitch)SQLiteCpp $(LibrarySwitch)sqlite3 $(LibrarySwitch)log4cpp 
ArLibs                 :=  "Security_Access_Control" "Common" "pthread" "avrocpp" "zmq" "boost_system" "SQLiteCpp" "sqlite3" "log4cpp" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/local/lib $(LibraryPathSwitch)/usr/lib/x86_64-linux-gnu $(LibraryPathSwitch)../Common/bin/Release $(LibraryPathSwitch)../Security_Access_Control/bin/Release 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -O2 -Wall -std=c++11 -m64 -Weffc++ $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
LD_LIBRARY_PATH:=$LD_LIBRARY_PATH:/home/alberto/Documents/01_gs4cubesat/C++Server/Common/bin/Release:/home/alberto/Documents/01_gs4cubesat/C++Server/Security_Access_Control/bin/Release
Objects0=$(IntermediateDirectory)/src_tc_processor_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_TcProcessorMessageProcessor.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_TcProcessorModuleManager.cpp$(ObjectSuffix) 



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
	@test -d ./obj/Release || $(MakeDirCommand) ./obj/Release


$(IntermediateDirectory)/.d:
	@test -d ./obj/Release || $(MakeDirCommand) ./obj/Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_tc_processor_main.cpp$(ObjectSuffix): src/tc_processor_main.cpp $(IntermediateDirectory)/src_tc_processor_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/TC_Processor/src/tc_processor_main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_tc_processor_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_tc_processor_main.cpp$(DependSuffix): src/tc_processor_main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_tc_processor_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_tc_processor_main.cpp$(DependSuffix) -MM src/tc_processor_main.cpp

$(IntermediateDirectory)/src_tc_processor_main.cpp$(PreprocessSuffix): src/tc_processor_main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_tc_processor_main.cpp$(PreprocessSuffix) src/tc_processor_main.cpp

$(IntermediateDirectory)/src_TcProcessorMessageProcessor.cpp$(ObjectSuffix): src/TcProcessorMessageProcessor.cpp $(IntermediateDirectory)/src_TcProcessorMessageProcessor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/TC_Processor/src/TcProcessorMessageProcessor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_TcProcessorMessageProcessor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_TcProcessorMessageProcessor.cpp$(DependSuffix): src/TcProcessorMessageProcessor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_TcProcessorMessageProcessor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_TcProcessorMessageProcessor.cpp$(DependSuffix) -MM src/TcProcessorMessageProcessor.cpp

$(IntermediateDirectory)/src_TcProcessorMessageProcessor.cpp$(PreprocessSuffix): src/TcProcessorMessageProcessor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_TcProcessorMessageProcessor.cpp$(PreprocessSuffix) src/TcProcessorMessageProcessor.cpp

$(IntermediateDirectory)/src_TcProcessorModuleManager.cpp$(ObjectSuffix): src/TcProcessorModuleManager.cpp $(IntermediateDirectory)/src_TcProcessorModuleManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/TC_Processor/src/TcProcessorModuleManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_TcProcessorModuleManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_TcProcessorModuleManager.cpp$(DependSuffix): src/TcProcessorModuleManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_TcProcessorModuleManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_TcProcessorModuleManager.cpp$(DependSuffix) -MM src/TcProcessorModuleManager.cpp

$(IntermediateDirectory)/src_TcProcessorModuleManager.cpp$(PreprocessSuffix): src/TcProcessorModuleManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_TcProcessorModuleManager.cpp$(PreprocessSuffix) src/TcProcessorModuleManager.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./obj/Release/



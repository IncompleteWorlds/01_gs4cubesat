##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=MCS
ConfigurationName      :=Release
WorkspacePath          :=/home/alberto/Documents/01_gs4cubesat
ProjectPath            :=/home/alberto/Documents/01_gs4cubesat/C++Server/MCS
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
ObjectsFileList        :="MCS.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)include $(IncludeSwitch)include/messages $(IncludeSwitch)../Common/include $(IncludeSwitch)../Security_Access_Control/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)Security_Access_Control $(LibrarySwitch)Common $(LibrarySwitch)pthread $(LibrarySwitch)avrocpp $(LibrarySwitch)zmq $(LibrarySwitch)log4cpp 
ArLibs                 :=  "Security_Access_Control" "Common" "pthread" "avrocpp" "zmq" "log4cpp" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/local/lib $(LibraryPathSwitch)/usr/lib/x86_64-linux-gnu $(LibraryPathSwitch)../Common/bin/Debug $(LibraryPathSwitch)../Security_Access_Control/bin/Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -O2 -Wall -fexceptions -std=c++11 -Weffc++ -m64 $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
LD_LIBRARY_PATH:=$LD_LIBRARY_PATH:/home/alberto/Documents/01_gs4cubesat/C++Server/Common/bin/Release:/home/alberto/Documents/01_gs4cubesat/C++Server/Security_Access_Control/bin/Release
Objects0=$(IntermediateDirectory)/src_messages_ExampleMcsMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_HKTM_Dispatcher.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_McsModuleManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_CommandManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_FileManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_mcs_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ExternalIF.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_McsMessageProcessor.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/src_messages_ExampleMcsMessage.cpp$(ObjectSuffix): src/messages/ExampleMcsMessage.cpp $(IntermediateDirectory)/src_messages_ExampleMcsMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/MCS/src/messages/ExampleMcsMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_ExampleMcsMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_ExampleMcsMessage.cpp$(DependSuffix): src/messages/ExampleMcsMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_ExampleMcsMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_ExampleMcsMessage.cpp$(DependSuffix) -MM src/messages/ExampleMcsMessage.cpp

$(IntermediateDirectory)/src_messages_ExampleMcsMessage.cpp$(PreprocessSuffix): src/messages/ExampleMcsMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_ExampleMcsMessage.cpp$(PreprocessSuffix) src/messages/ExampleMcsMessage.cpp

$(IntermediateDirectory)/src_HKTM_Dispatcher.cpp$(ObjectSuffix): src/HKTM_Dispatcher.cpp $(IntermediateDirectory)/src_HKTM_Dispatcher.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/MCS/src/HKTM_Dispatcher.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_HKTM_Dispatcher.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_HKTM_Dispatcher.cpp$(DependSuffix): src/HKTM_Dispatcher.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_HKTM_Dispatcher.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_HKTM_Dispatcher.cpp$(DependSuffix) -MM src/HKTM_Dispatcher.cpp

$(IntermediateDirectory)/src_HKTM_Dispatcher.cpp$(PreprocessSuffix): src/HKTM_Dispatcher.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_HKTM_Dispatcher.cpp$(PreprocessSuffix) src/HKTM_Dispatcher.cpp

$(IntermediateDirectory)/src_McsModuleManager.cpp$(ObjectSuffix): src/McsModuleManager.cpp $(IntermediateDirectory)/src_McsModuleManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/MCS/src/McsModuleManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_McsModuleManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_McsModuleManager.cpp$(DependSuffix): src/McsModuleManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_McsModuleManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_McsModuleManager.cpp$(DependSuffix) -MM src/McsModuleManager.cpp

$(IntermediateDirectory)/src_McsModuleManager.cpp$(PreprocessSuffix): src/McsModuleManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_McsModuleManager.cpp$(PreprocessSuffix) src/McsModuleManager.cpp

$(IntermediateDirectory)/src_CommandManager.cpp$(ObjectSuffix): src/CommandManager.cpp $(IntermediateDirectory)/src_CommandManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/MCS/src/CommandManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_CommandManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_CommandManager.cpp$(DependSuffix): src/CommandManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_CommandManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_CommandManager.cpp$(DependSuffix) -MM src/CommandManager.cpp

$(IntermediateDirectory)/src_CommandManager.cpp$(PreprocessSuffix): src/CommandManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_CommandManager.cpp$(PreprocessSuffix) src/CommandManager.cpp

$(IntermediateDirectory)/src_FileManager.cpp$(ObjectSuffix): src/FileManager.cpp $(IntermediateDirectory)/src_FileManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/MCS/src/FileManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_FileManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_FileManager.cpp$(DependSuffix): src/FileManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_FileManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_FileManager.cpp$(DependSuffix) -MM src/FileManager.cpp

$(IntermediateDirectory)/src_FileManager.cpp$(PreprocessSuffix): src/FileManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_FileManager.cpp$(PreprocessSuffix) src/FileManager.cpp

$(IntermediateDirectory)/src_mcs_main.cpp$(ObjectSuffix): src/mcs_main.cpp $(IntermediateDirectory)/src_mcs_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/MCS/src/mcs_main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_mcs_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_mcs_main.cpp$(DependSuffix): src/mcs_main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_mcs_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_mcs_main.cpp$(DependSuffix) -MM src/mcs_main.cpp

$(IntermediateDirectory)/src_mcs_main.cpp$(PreprocessSuffix): src/mcs_main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_mcs_main.cpp$(PreprocessSuffix) src/mcs_main.cpp

$(IntermediateDirectory)/src_ExternalIF.cpp$(ObjectSuffix): src/ExternalIF.cpp $(IntermediateDirectory)/src_ExternalIF.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/MCS/src/ExternalIF.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ExternalIF.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ExternalIF.cpp$(DependSuffix): src/ExternalIF.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ExternalIF.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ExternalIF.cpp$(DependSuffix) -MM src/ExternalIF.cpp

$(IntermediateDirectory)/src_ExternalIF.cpp$(PreprocessSuffix): src/ExternalIF.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ExternalIF.cpp$(PreprocessSuffix) src/ExternalIF.cpp

$(IntermediateDirectory)/src_McsMessageProcessor.cpp$(ObjectSuffix): src/McsMessageProcessor.cpp $(IntermediateDirectory)/src_McsMessageProcessor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/MCS/src/McsMessageProcessor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_McsMessageProcessor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_McsMessageProcessor.cpp$(DependSuffix): src/McsMessageProcessor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_McsMessageProcessor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_McsMessageProcessor.cpp$(DependSuffix) -MM src/McsMessageProcessor.cpp

$(IntermediateDirectory)/src_McsMessageProcessor.cpp$(PreprocessSuffix): src/McsMessageProcessor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_McsMessageProcessor.cpp$(PreprocessSuffix) src/McsMessageProcessor.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./obj/Release/



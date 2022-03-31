##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=TM_Processor
ConfigurationName      :=Release
WorkspacePath          :=/home/alberto/Documents/01_gs4cubesat
ProjectPath            :=/home/alberto/Documents/01_gs4cubesat/C++Server/HKTM_Processor
IntermediateDirectory  :=./obj/Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alberto
Date                   :=15/07/17
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
ObjectsFileList        :="TM_Processor.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./include $(IncludeSwitch)../Common/include $(IncludeSwitch)../Security/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)Common $(LibrarySwitch)Security_Access_Control $(LibrarySwitch)avrocpp $(LibrarySwitch)zmq $(LibrarySwitch)pthread $(LibrarySwitch)boost_system $(LibrarySwitch)SQLiteCpp $(LibrarySwitch)sqlite3 
ArLibs                 :=  "Common" "Security_Access_Control" "avrocpp" "zmq" "pthread" "boost_system" "SQLiteCpp" "sqlite3" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/local/lib $(LibraryPathSwitch)../Common/bin/Release $(LibraryPathSwitch)../Security_Access_Control/bin/Release 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -O2 -std=c++11 -Wall -fexceptions -m64 -Weffc++ $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_CspLayer.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_CcsdsLayer.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ApplicationLayer.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_HkTmProcessorModuleManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_HdlcLayer.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Ax25Layer.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_HkTmProcessorMessageProcessor.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_tm_processor_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_KissLayer.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_BaseLayer.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/include_DynamicFrame.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_NewRawFrameMessage.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/src_CspLayer.cpp$(ObjectSuffix): src/CspLayer.cpp $(IntermediateDirectory)/src_CspLayer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/HKTM_Processor/src/CspLayer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_CspLayer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_CspLayer.cpp$(DependSuffix): src/CspLayer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_CspLayer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_CspLayer.cpp$(DependSuffix) -MM src/CspLayer.cpp

$(IntermediateDirectory)/src_CspLayer.cpp$(PreprocessSuffix): src/CspLayer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_CspLayer.cpp$(PreprocessSuffix) src/CspLayer.cpp

$(IntermediateDirectory)/src_CcsdsLayer.cpp$(ObjectSuffix): src/CcsdsLayer.cpp $(IntermediateDirectory)/src_CcsdsLayer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/HKTM_Processor/src/CcsdsLayer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_CcsdsLayer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_CcsdsLayer.cpp$(DependSuffix): src/CcsdsLayer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_CcsdsLayer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_CcsdsLayer.cpp$(DependSuffix) -MM src/CcsdsLayer.cpp

$(IntermediateDirectory)/src_CcsdsLayer.cpp$(PreprocessSuffix): src/CcsdsLayer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_CcsdsLayer.cpp$(PreprocessSuffix) src/CcsdsLayer.cpp

$(IntermediateDirectory)/src_ApplicationLayer.cpp$(ObjectSuffix): src/ApplicationLayer.cpp $(IntermediateDirectory)/src_ApplicationLayer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/HKTM_Processor/src/ApplicationLayer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ApplicationLayer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ApplicationLayer.cpp$(DependSuffix): src/ApplicationLayer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ApplicationLayer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ApplicationLayer.cpp$(DependSuffix) -MM src/ApplicationLayer.cpp

$(IntermediateDirectory)/src_ApplicationLayer.cpp$(PreprocessSuffix): src/ApplicationLayer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ApplicationLayer.cpp$(PreprocessSuffix) src/ApplicationLayer.cpp

$(IntermediateDirectory)/src_HkTmProcessorModuleManager.cpp$(ObjectSuffix): src/HkTmProcessorModuleManager.cpp $(IntermediateDirectory)/src_HkTmProcessorModuleManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/HKTM_Processor/src/HkTmProcessorModuleManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_HkTmProcessorModuleManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_HkTmProcessorModuleManager.cpp$(DependSuffix): src/HkTmProcessorModuleManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_HkTmProcessorModuleManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_HkTmProcessorModuleManager.cpp$(DependSuffix) -MM src/HkTmProcessorModuleManager.cpp

$(IntermediateDirectory)/src_HkTmProcessorModuleManager.cpp$(PreprocessSuffix): src/HkTmProcessorModuleManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_HkTmProcessorModuleManager.cpp$(PreprocessSuffix) src/HkTmProcessorModuleManager.cpp

$(IntermediateDirectory)/src_HdlcLayer.cpp$(ObjectSuffix): src/HdlcLayer.cpp $(IntermediateDirectory)/src_HdlcLayer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/HKTM_Processor/src/HdlcLayer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_HdlcLayer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_HdlcLayer.cpp$(DependSuffix): src/HdlcLayer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_HdlcLayer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_HdlcLayer.cpp$(DependSuffix) -MM src/HdlcLayer.cpp

$(IntermediateDirectory)/src_HdlcLayer.cpp$(PreprocessSuffix): src/HdlcLayer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_HdlcLayer.cpp$(PreprocessSuffix) src/HdlcLayer.cpp

$(IntermediateDirectory)/src_Ax25Layer.cpp$(ObjectSuffix): src/Ax25Layer.cpp $(IntermediateDirectory)/src_Ax25Layer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/HKTM_Processor/src/Ax25Layer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Ax25Layer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Ax25Layer.cpp$(DependSuffix): src/Ax25Layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Ax25Layer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Ax25Layer.cpp$(DependSuffix) -MM src/Ax25Layer.cpp

$(IntermediateDirectory)/src_Ax25Layer.cpp$(PreprocessSuffix): src/Ax25Layer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Ax25Layer.cpp$(PreprocessSuffix) src/Ax25Layer.cpp

$(IntermediateDirectory)/src_HkTmProcessorMessageProcessor.cpp$(ObjectSuffix): src/HkTmProcessorMessageProcessor.cpp $(IntermediateDirectory)/src_HkTmProcessorMessageProcessor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/HKTM_Processor/src/HkTmProcessorMessageProcessor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_HkTmProcessorMessageProcessor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_HkTmProcessorMessageProcessor.cpp$(DependSuffix): src/HkTmProcessorMessageProcessor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_HkTmProcessorMessageProcessor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_HkTmProcessorMessageProcessor.cpp$(DependSuffix) -MM src/HkTmProcessorMessageProcessor.cpp

$(IntermediateDirectory)/src_HkTmProcessorMessageProcessor.cpp$(PreprocessSuffix): src/HkTmProcessorMessageProcessor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_HkTmProcessorMessageProcessor.cpp$(PreprocessSuffix) src/HkTmProcessorMessageProcessor.cpp

$(IntermediateDirectory)/src_tm_processor_main.cpp$(ObjectSuffix): src/tm_processor_main.cpp $(IntermediateDirectory)/src_tm_processor_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/HKTM_Processor/src/tm_processor_main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_tm_processor_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_tm_processor_main.cpp$(DependSuffix): src/tm_processor_main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_tm_processor_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_tm_processor_main.cpp$(DependSuffix) -MM src/tm_processor_main.cpp

$(IntermediateDirectory)/src_tm_processor_main.cpp$(PreprocessSuffix): src/tm_processor_main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_tm_processor_main.cpp$(PreprocessSuffix) src/tm_processor_main.cpp

$(IntermediateDirectory)/src_KissLayer.cpp$(ObjectSuffix): src/KissLayer.cpp $(IntermediateDirectory)/src_KissLayer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/HKTM_Processor/src/KissLayer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_KissLayer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_KissLayer.cpp$(DependSuffix): src/KissLayer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_KissLayer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_KissLayer.cpp$(DependSuffix) -MM src/KissLayer.cpp

$(IntermediateDirectory)/src_KissLayer.cpp$(PreprocessSuffix): src/KissLayer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_KissLayer.cpp$(PreprocessSuffix) src/KissLayer.cpp

$(IntermediateDirectory)/src_BaseLayer.cpp$(ObjectSuffix): src/BaseLayer.cpp $(IntermediateDirectory)/src_BaseLayer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/HKTM_Processor/src/BaseLayer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_BaseLayer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_BaseLayer.cpp$(DependSuffix): src/BaseLayer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_BaseLayer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_BaseLayer.cpp$(DependSuffix) -MM src/BaseLayer.cpp

$(IntermediateDirectory)/src_BaseLayer.cpp$(PreprocessSuffix): src/BaseLayer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_BaseLayer.cpp$(PreprocessSuffix) src/BaseLayer.cpp

$(IntermediateDirectory)/include_DynamicFrame.cpp$(ObjectSuffix): include/DynamicFrame.cpp $(IntermediateDirectory)/include_DynamicFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/HKTM_Processor/include/DynamicFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/include_DynamicFrame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/include_DynamicFrame.cpp$(DependSuffix): include/DynamicFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/include_DynamicFrame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/include_DynamicFrame.cpp$(DependSuffix) -MM include/DynamicFrame.cpp

$(IntermediateDirectory)/include_DynamicFrame.cpp$(PreprocessSuffix): include/DynamicFrame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/include_DynamicFrame.cpp$(PreprocessSuffix) include/DynamicFrame.cpp

$(IntermediateDirectory)/src_messages_NewRawFrameMessage.cpp$(ObjectSuffix): src/messages/NewRawFrameMessage.cpp $(IntermediateDirectory)/src_messages_NewRawFrameMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/HKTM_Processor/src/messages/NewRawFrameMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_NewRawFrameMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_NewRawFrameMessage.cpp$(DependSuffix): src/messages/NewRawFrameMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_NewRawFrameMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_NewRawFrameMessage.cpp$(DependSuffix) -MM src/messages/NewRawFrameMessage.cpp

$(IntermediateDirectory)/src_messages_NewRawFrameMessage.cpp$(PreprocessSuffix): src/messages/NewRawFrameMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_NewRawFrameMessage.cpp$(PreprocessSuffix) src/messages/NewRawFrameMessage.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./obj/Release/



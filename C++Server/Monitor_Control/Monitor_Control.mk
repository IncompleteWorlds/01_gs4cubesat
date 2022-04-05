##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=Monitor_Control
ConfigurationName      :=Release
WorkspacePath          :=/home/alberto/Documents/01_gs4cubesat
ProjectPath            :=/home/alberto/Documents/01_gs4cubesat/C++Server/Monitor_Control
IntermediateDirectory  :=./obj/Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alberto
Date                   :=30/06/18
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
ObjectsFileList        :="Monitor_Control.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)include $(IncludeSwitch)../Common/include $(IncludeSwitch)../Security_Access_Control/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)Security_Access_Control $(LibrarySwitch)Common $(LibrarySwitch)pthread $(LibrarySwitch)avrocpp $(LibrarySwitch)zmq $(LibrarySwitch)log4cpp 
ArLibs                 :=  "Security_Access_Control" "Common" "pthread" "avrocpp" "zmq" "log4cpp" 
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
Objects0=$(IntermediateDirectory)/src_EventMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_m_c_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_StartUpMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_M_CModuleManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_RegisterUserMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_M_CMessageProcessor.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_LoginMessage.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/src_EventMessage.cpp$(ObjectSuffix): src/EventMessage.cpp $(IntermediateDirectory)/src_EventMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Monitor_Control/src/EventMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_EventMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_EventMessage.cpp$(DependSuffix): src/EventMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_EventMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_EventMessage.cpp$(DependSuffix) -MM src/EventMessage.cpp

$(IntermediateDirectory)/src_EventMessage.cpp$(PreprocessSuffix): src/EventMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_EventMessage.cpp$(PreprocessSuffix) src/EventMessage.cpp

$(IntermediateDirectory)/src_m_c_main.cpp$(ObjectSuffix): src/m_c_main.cpp $(IntermediateDirectory)/src_m_c_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Monitor_Control/src/m_c_main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_m_c_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_m_c_main.cpp$(DependSuffix): src/m_c_main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_m_c_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_m_c_main.cpp$(DependSuffix) -MM src/m_c_main.cpp

$(IntermediateDirectory)/src_m_c_main.cpp$(PreprocessSuffix): src/m_c_main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_m_c_main.cpp$(PreprocessSuffix) src/m_c_main.cpp

$(IntermediateDirectory)/src_StartUpMessage.cpp$(ObjectSuffix): src/StartUpMessage.cpp $(IntermediateDirectory)/src_StartUpMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Monitor_Control/src/StartUpMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_StartUpMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_StartUpMessage.cpp$(DependSuffix): src/StartUpMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_StartUpMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_StartUpMessage.cpp$(DependSuffix) -MM src/StartUpMessage.cpp

$(IntermediateDirectory)/src_StartUpMessage.cpp$(PreprocessSuffix): src/StartUpMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_StartUpMessage.cpp$(PreprocessSuffix) src/StartUpMessage.cpp

$(IntermediateDirectory)/src_M_CModuleManager.cpp$(ObjectSuffix): src/M_CModuleManager.cpp $(IntermediateDirectory)/src_M_CModuleManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Monitor_Control/src/M_CModuleManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_M_CModuleManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_M_CModuleManager.cpp$(DependSuffix): src/M_CModuleManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_M_CModuleManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_M_CModuleManager.cpp$(DependSuffix) -MM src/M_CModuleManager.cpp

$(IntermediateDirectory)/src_M_CModuleManager.cpp$(PreprocessSuffix): src/M_CModuleManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_M_CModuleManager.cpp$(PreprocessSuffix) src/M_CModuleManager.cpp

$(IntermediateDirectory)/src_RegisterUserMessage.cpp$(ObjectSuffix): src/RegisterUserMessage.cpp $(IntermediateDirectory)/src_RegisterUserMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Monitor_Control/src/RegisterUserMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_RegisterUserMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_RegisterUserMessage.cpp$(DependSuffix): src/RegisterUserMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_RegisterUserMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_RegisterUserMessage.cpp$(DependSuffix) -MM src/RegisterUserMessage.cpp

$(IntermediateDirectory)/src_RegisterUserMessage.cpp$(PreprocessSuffix): src/RegisterUserMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_RegisterUserMessage.cpp$(PreprocessSuffix) src/RegisterUserMessage.cpp

$(IntermediateDirectory)/src_M_CMessageProcessor.cpp$(ObjectSuffix): src/M_CMessageProcessor.cpp $(IntermediateDirectory)/src_M_CMessageProcessor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Monitor_Control/src/M_CMessageProcessor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_M_CMessageProcessor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_M_CMessageProcessor.cpp$(DependSuffix): src/M_CMessageProcessor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_M_CMessageProcessor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_M_CMessageProcessor.cpp$(DependSuffix) -MM src/M_CMessageProcessor.cpp

$(IntermediateDirectory)/src_M_CMessageProcessor.cpp$(PreprocessSuffix): src/M_CMessageProcessor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_M_CMessageProcessor.cpp$(PreprocessSuffix) src/M_CMessageProcessor.cpp

$(IntermediateDirectory)/src_LoginMessage.cpp$(ObjectSuffix): src/LoginMessage.cpp $(IntermediateDirectory)/src_LoginMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Monitor_Control/src/LoginMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LoginMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LoginMessage.cpp$(DependSuffix): src/LoginMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_LoginMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_LoginMessage.cpp$(DependSuffix) -MM src/LoginMessage.cpp

$(IntermediateDirectory)/src_LoginMessage.cpp$(PreprocessSuffix): src/LoginMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LoginMessage.cpp$(PreprocessSuffix) src/LoginMessage.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./obj/Release/



##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Monitor_Control
ConfigurationName      :=Debug
WorkspacePath          :=/home/alberto/Projects/01_gs4cubesat/C++Server
ProjectPath            :=/home/alberto/Projects/01_gs4cubesat/C++Server/Monitor_Control
IntermediateDirectory  :=./obj/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alberto
Date                   :=08/11/19
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
ObjectsFileList        :="Monitor_Control.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)include $(IncludeSwitch)../Common/include $(IncludeSwitch)../Security_Access_Control/include $(IncludeSwitch)../Common/include/clients 
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
CXXFLAGS :=  -g -O0 -std=c++11 -Wall -m64 -Weffc++ $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
LD_LIBRARY_PATH:=$LD_LIBRARY_PATH:/home/alberto/Projects/01_gs4cubesat/C++Server/Common/bin/Debug:/home/alberto/Projects/01_gs4cubesat/C++Server/Security_Access_Control/bin/Debug
Objects0=$(IntermediateDirectory)/src_LoginMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_M_CMessageProcessor.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_StartUpMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_M_CModuleManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_RegisterUserMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_m_c_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_EventMessage.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/src_LoginMessage.cpp$(ObjectSuffix): src/LoginMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Monitor_Control/src/LoginMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LoginMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LoginMessage.cpp$(PreprocessSuffix): src/LoginMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LoginMessage.cpp$(PreprocessSuffix) src/LoginMessage.cpp

$(IntermediateDirectory)/src_M_CMessageProcessor.cpp$(ObjectSuffix): src/M_CMessageProcessor.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Monitor_Control/src/M_CMessageProcessor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_M_CMessageProcessor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_M_CMessageProcessor.cpp$(PreprocessSuffix): src/M_CMessageProcessor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_M_CMessageProcessor.cpp$(PreprocessSuffix) src/M_CMessageProcessor.cpp

$(IntermediateDirectory)/src_StartUpMessage.cpp$(ObjectSuffix): src/StartUpMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Monitor_Control/src/StartUpMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_StartUpMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_StartUpMessage.cpp$(PreprocessSuffix): src/StartUpMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_StartUpMessage.cpp$(PreprocessSuffix) src/StartUpMessage.cpp

$(IntermediateDirectory)/src_M_CModuleManager.cpp$(ObjectSuffix): src/M_CModuleManager.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Monitor_Control/src/M_CModuleManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_M_CModuleManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_M_CModuleManager.cpp$(PreprocessSuffix): src/M_CModuleManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_M_CModuleManager.cpp$(PreprocessSuffix) src/M_CModuleManager.cpp

$(IntermediateDirectory)/src_RegisterUserMessage.cpp$(ObjectSuffix): src/RegisterUserMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Monitor_Control/src/RegisterUserMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_RegisterUserMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_RegisterUserMessage.cpp$(PreprocessSuffix): src/RegisterUserMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_RegisterUserMessage.cpp$(PreprocessSuffix) src/RegisterUserMessage.cpp

$(IntermediateDirectory)/src_m_c_main.cpp$(ObjectSuffix): src/m_c_main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Monitor_Control/src/m_c_main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_m_c_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_m_c_main.cpp$(PreprocessSuffix): src/m_c_main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_m_c_main.cpp$(PreprocessSuffix) src/m_c_main.cpp

$(IntermediateDirectory)/src_EventMessage.cpp$(ObjectSuffix): src/EventMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Monitor_Control/src/EventMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_EventMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_EventMessage.cpp$(PreprocessSuffix): src/EventMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_EventMessage.cpp$(PreprocessSuffix) src/EventMessage.cpp

##
## Clean
##
clean:
	$(RM) -r ./obj/Debug/



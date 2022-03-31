##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=FDS
ConfigurationName      :=Debug
WorkspacePath          :=/home/alberto/Projects/01_gs4cubesat/C++Server
ProjectPath            :=/home/alberto/Projects/01_gs4cubesat/C++Server/FDS
IntermediateDirectory  :=./obj/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alberto
Date                   :=22/03/20
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
ObjectsFileList        :="FDS.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)include $(IncludeSwitch)include/messages $(IncludeSwitch)../Common/include $(IncludeSwitch)../Security_Access_Control/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)Common $(LibrarySwitch)Security_Access_Control $(LibrarySwitch)avrocpp $(LibrarySwitch)nng $(LibrarySwitch)SQLiteCpp $(LibrarySwitch)sqlite3 $(LibrarySwitch)pthread $(LibrarySwitch)log4cpp $(LibrarySwitch)boost_system $(LibrarySwitch)ssl $(LibrarySwitch)crypto $(LibrarySwitch)cpprest 
ArLibs                 :=  "Common" "Security_Access_Control" "avrocpp" "nng" "SQLiteCpp" "sqlite3" "pthread" "log4cpp" "boost_system" "ssl" "crypto" "cpprest" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/local/lib $(LibraryPathSwitch)../Common/bin/Debug $(LibraryPathSwitch)../Security_Access_Control/bin/Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -std=c++14 -Wall -fexceptions -Weffc++ $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
LD_LIBRARY_PATH:=$LD_LIBRARY_PATH:/home/alberto/Projects/01_gs4cubesat/C++Server/Common/bin/Debug:/home/alberto/Projects/01_gs4cubesat/C++Server/Security_Access_Control/bin/Debug
Objects0=$(IntermediateDirectory)/src_messages_StopExecutionMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_GetPassesMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_fds_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_FdsModuleManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_FdsMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_FdsMessageProcessor.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_FdsDatabase.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_StartExecutionMessage.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/src_messages_StopExecutionMessage.cpp$(ObjectSuffix): src/messages/StopExecutionMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/FDS/src/messages/StopExecutionMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_StopExecutionMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_StopExecutionMessage.cpp$(PreprocessSuffix): src/messages/StopExecutionMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_StopExecutionMessage.cpp$(PreprocessSuffix) src/messages/StopExecutionMessage.cpp

$(IntermediateDirectory)/src_messages_GetPassesMessage.cpp$(ObjectSuffix): src/messages/GetPassesMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/FDS/src/messages/GetPassesMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_GetPassesMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_GetPassesMessage.cpp$(PreprocessSuffix): src/messages/GetPassesMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_GetPassesMessage.cpp$(PreprocessSuffix) src/messages/GetPassesMessage.cpp

$(IntermediateDirectory)/src_fds_main.cpp$(ObjectSuffix): src/fds_main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/FDS/src/fds_main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_fds_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_fds_main.cpp$(PreprocessSuffix): src/fds_main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_fds_main.cpp$(PreprocessSuffix) src/fds_main.cpp

$(IntermediateDirectory)/src_FdsModuleManager.cpp$(ObjectSuffix): src/FdsModuleManager.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/FDS/src/FdsModuleManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_FdsModuleManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_FdsModuleManager.cpp$(PreprocessSuffix): src/FdsModuleManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_FdsModuleManager.cpp$(PreprocessSuffix) src/FdsModuleManager.cpp

$(IntermediateDirectory)/src_messages_FdsMessage.cpp$(ObjectSuffix): src/messages/FdsMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/FDS/src/messages/FdsMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_FdsMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_FdsMessage.cpp$(PreprocessSuffix): src/messages/FdsMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_FdsMessage.cpp$(PreprocessSuffix) src/messages/FdsMessage.cpp

$(IntermediateDirectory)/src_FdsMessageProcessor.cpp$(ObjectSuffix): src/FdsMessageProcessor.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/FDS/src/FdsMessageProcessor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_FdsMessageProcessor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_FdsMessageProcessor.cpp$(PreprocessSuffix): src/FdsMessageProcessor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_FdsMessageProcessor.cpp$(PreprocessSuffix) src/FdsMessageProcessor.cpp

$(IntermediateDirectory)/src_FdsDatabase.cpp$(ObjectSuffix): src/FdsDatabase.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/FDS/src/FdsDatabase.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_FdsDatabase.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_FdsDatabase.cpp$(PreprocessSuffix): src/FdsDatabase.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_FdsDatabase.cpp$(PreprocessSuffix) src/FdsDatabase.cpp

$(IntermediateDirectory)/src_messages_StartExecutionMessage.cpp$(ObjectSuffix): src/messages/StartExecutionMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/FDS/src/messages/StartExecutionMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_StartExecutionMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_StartExecutionMessage.cpp$(PreprocessSuffix): src/messages/StartExecutionMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_StartExecutionMessage.cpp$(PreprocessSuffix) src/messages/StartExecutionMessage.cpp

##
## Clean
##
clean:
	$(RM) -r ./obj/Debug/



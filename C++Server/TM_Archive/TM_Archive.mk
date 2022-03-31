##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=TM_Archive
ConfigurationName      :=Debug
WorkspacePath          :="/media/alberto/LXLE Linux/home/alberto/Projects/01_gs4cubesat"
ProjectPath            :="/media/alberto/LXLE Linux/home/alberto/Projects/01_gs4cubesat/C++Server/TM_Archive"
IntermediateDirectory  :=./obj/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alberto
Date                   :=16/08/19
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
ObjectsFileList        :="TM_Archive.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)include $(IncludeSwitch)../Common/include $(IncludeSwitch)../Security_Access_Control/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)Common $(LibrarySwitch)Security_Access_Control $(LibrarySwitch)pthread $(LibrarySwitch)boost_system $(LibrarySwitch)SQLiteCpp $(LibrarySwitch)sqlite3 $(LibrarySwitch)avrocpp $(LibrarySwitch)zmq $(LibrarySwitch)log4cpp 
ArLibs                 :=  "Common" "Security_Access_Control" "pthread" "boost_system" "SQLiteCpp" "sqlite3" "avrocpp" "zmq" "log4cpp" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/local/lib $(LibraryPathSwitch)/usr/lib/x86_64-linux-gnu $(LibraryPathSwitch)../Common/bin/Debug $(LibraryPathSwitch)../Security_Access_Control/bin/Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -std=c++11 -Wall -fexceptions -m64 -Weffc++ $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
LD_LIBRARY_PATH:=$LD_LIBRARY_PATH:/media/alberto/LXLE Linux/home/alberto/Projects/01_gs4cubesat/C++Server/Common/bin/Debug:/media/alberto/LXLE Linux/home/alberto/Projects/01_gs4cubesat/C++Server/Security_Access_Control/bin/Debug
Objects0=$(IntermediateDirectory)/src_ArchiveDatabase.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_EventMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ArchiveMessageProcessor.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ArchiveModuleManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_archive_main.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/src_ArchiveDatabase.cpp$(ObjectSuffix): src/ArchiveDatabase.cpp $(IntermediateDirectory)/src_ArchiveDatabase.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/alberto/LXLE Linux/home/alberto/Projects/01_gs4cubesat/C++Server/TM_Archive/src/ArchiveDatabase.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ArchiveDatabase.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ArchiveDatabase.cpp$(DependSuffix): src/ArchiveDatabase.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ArchiveDatabase.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ArchiveDatabase.cpp$(DependSuffix) -MM src/ArchiveDatabase.cpp

$(IntermediateDirectory)/src_ArchiveDatabase.cpp$(PreprocessSuffix): src/ArchiveDatabase.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ArchiveDatabase.cpp$(PreprocessSuffix) src/ArchiveDatabase.cpp

$(IntermediateDirectory)/src_EventMessage.cpp$(ObjectSuffix): src/EventMessage.cpp $(IntermediateDirectory)/src_EventMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/alberto/LXLE Linux/home/alberto/Projects/01_gs4cubesat/C++Server/TM_Archive/src/EventMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_EventMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_EventMessage.cpp$(DependSuffix): src/EventMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_EventMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_EventMessage.cpp$(DependSuffix) -MM src/EventMessage.cpp

$(IntermediateDirectory)/src_EventMessage.cpp$(PreprocessSuffix): src/EventMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_EventMessage.cpp$(PreprocessSuffix) src/EventMessage.cpp

$(IntermediateDirectory)/src_ArchiveMessageProcessor.cpp$(ObjectSuffix): src/ArchiveMessageProcessor.cpp $(IntermediateDirectory)/src_ArchiveMessageProcessor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/alberto/LXLE Linux/home/alberto/Projects/01_gs4cubesat/C++Server/TM_Archive/src/ArchiveMessageProcessor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ArchiveMessageProcessor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ArchiveMessageProcessor.cpp$(DependSuffix): src/ArchiveMessageProcessor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ArchiveMessageProcessor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ArchiveMessageProcessor.cpp$(DependSuffix) -MM src/ArchiveMessageProcessor.cpp

$(IntermediateDirectory)/src_ArchiveMessageProcessor.cpp$(PreprocessSuffix): src/ArchiveMessageProcessor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ArchiveMessageProcessor.cpp$(PreprocessSuffix) src/ArchiveMessageProcessor.cpp

$(IntermediateDirectory)/src_ArchiveModuleManager.cpp$(ObjectSuffix): src/ArchiveModuleManager.cpp $(IntermediateDirectory)/src_ArchiveModuleManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/alberto/LXLE Linux/home/alberto/Projects/01_gs4cubesat/C++Server/TM_Archive/src/ArchiveModuleManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ArchiveModuleManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ArchiveModuleManager.cpp$(DependSuffix): src/ArchiveModuleManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ArchiveModuleManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ArchiveModuleManager.cpp$(DependSuffix) -MM src/ArchiveModuleManager.cpp

$(IntermediateDirectory)/src_ArchiveModuleManager.cpp$(PreprocessSuffix): src/ArchiveModuleManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ArchiveModuleManager.cpp$(PreprocessSuffix) src/ArchiveModuleManager.cpp

$(IntermediateDirectory)/src_archive_main.cpp$(ObjectSuffix): src/archive_main.cpp $(IntermediateDirectory)/src_archive_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/alberto/LXLE Linux/home/alberto/Projects/01_gs4cubesat/C++Server/TM_Archive/src/archive_main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_archive_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_archive_main.cpp$(DependSuffix): src/archive_main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_archive_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_archive_main.cpp$(DependSuffix) -MM src/archive_main.cpp

$(IntermediateDirectory)/src_archive_main.cpp$(PreprocessSuffix): src/archive_main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_archive_main.cpp$(PreprocessSuffix) src/archive_main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./obj/Debug/



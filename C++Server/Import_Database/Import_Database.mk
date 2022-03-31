##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Import_Database
ConfigurationName      :=Debug
WorkspacePath          :="/media/alberto/LXLE Linux/home/alberto/Projects/01_gs4cubesat"
ProjectPath            :="/media/alberto/LXLE Linux/home/alberto/Projects/01_gs4cubesat/C++Server/Import_Database"
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
ObjectsFileList        :="Import_Database.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)include $(IncludeSwitch)../Common/include $(IncludeSwitch)../Tools/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)Common $(LibrarySwitch)avrocpp $(LibrarySwitch)zmq $(LibrarySwitch)SQLiteCpp $(LibrarySwitch)sqlite3 $(LibrarySwitch)pthread $(LibrarySwitch)log4cpp 
ArLibs                 :=  "Common" "avrocpp" "zmq" "SQLiteCpp" "sqlite3" "pthread" "log4cpp" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/local/lib $(LibraryPathSwitch)../Common/bin/Debug 

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
LD_LIBRARY_PATH:=$LD_LIBRARY_PATH:/media/alberto/LXLE Linux/home/alberto/Projects/01_gs4cubesat/C++Server/Common/bin/Debug
Objects0=$(IntermediateDirectory)/src_BasicExcel.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Tools_src_ToolsDatabase.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ExcelFormat.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/src_BasicExcel.cpp$(ObjectSuffix): src/BasicExcel.cpp $(IntermediateDirectory)/src_BasicExcel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/alberto/LXLE Linux/home/alberto/Projects/01_gs4cubesat/C++Server/Import_Database/src/BasicExcel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_BasicExcel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_BasicExcel.cpp$(DependSuffix): src/BasicExcel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_BasicExcel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_BasicExcel.cpp$(DependSuffix) -MM src/BasicExcel.cpp

$(IntermediateDirectory)/src_BasicExcel.cpp$(PreprocessSuffix): src/BasicExcel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_BasicExcel.cpp$(PreprocessSuffix) src/BasicExcel.cpp

$(IntermediateDirectory)/up_Tools_src_ToolsDatabase.cpp$(ObjectSuffix): ../Tools/src/ToolsDatabase.cpp $(IntermediateDirectory)/up_Tools_src_ToolsDatabase.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/alberto/LXLE Linux/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/ToolsDatabase.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Tools_src_ToolsDatabase.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Tools_src_ToolsDatabase.cpp$(DependSuffix): ../Tools/src/ToolsDatabase.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Tools_src_ToolsDatabase.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Tools_src_ToolsDatabase.cpp$(DependSuffix) -MM ../Tools/src/ToolsDatabase.cpp

$(IntermediateDirectory)/up_Tools_src_ToolsDatabase.cpp$(PreprocessSuffix): ../Tools/src/ToolsDatabase.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Tools_src_ToolsDatabase.cpp$(PreprocessSuffix) ../Tools/src/ToolsDatabase.cpp

$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix): src/main.cpp $(IntermediateDirectory)/src_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/alberto/LXLE Linux/home/alberto/Projects/01_gs4cubesat/C++Server/Import_Database/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cpp$(DependSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.cpp$(DependSuffix) -MM src/main.cpp

$(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix): src/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix) src/main.cpp

$(IntermediateDirectory)/src_ExcelFormat.cpp$(ObjectSuffix): src/ExcelFormat.cpp $(IntermediateDirectory)/src_ExcelFormat.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/alberto/LXLE Linux/home/alberto/Projects/01_gs4cubesat/C++Server/Import_Database/src/ExcelFormat.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ExcelFormat.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ExcelFormat.cpp$(DependSuffix): src/ExcelFormat.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ExcelFormat.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ExcelFormat.cpp$(DependSuffix) -MM src/ExcelFormat.cpp

$(IntermediateDirectory)/src_ExcelFormat.cpp$(PreprocessSuffix): src/ExcelFormat.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ExcelFormat.cpp$(PreprocessSuffix) src/ExcelFormat.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./obj/Debug/



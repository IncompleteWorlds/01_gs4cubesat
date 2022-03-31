##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=OrbPropag
ConfigurationName      :=Debug
WorkspacePath          :=/home/alberto/Projects/01_gs4cubesat/C++Server
ProjectPath            :=/home/alberto/Projects/01_gs4cubesat/C++Server/OrbPropag
IntermediateDirectory  :=./obj/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=alberto
Date                   :=09/10/19
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
ObjectsFileList        :="OrbPropag.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)include $(IncludeSwitch)include/messages $(IncludeSwitch)../Common/include $(IncludeSwitch)../Security_Access_Control/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)Common $(LibrarySwitch)Security_Access_Control $(LibrarySwitch)avrocpp $(LibrarySwitch)zmq $(LibrarySwitch)SQLiteCpp $(LibrarySwitch)sqlite3 $(LibrarySwitch)pthread $(LibrarySwitch)log4cpp $(LibrarySwitch)c $(LibrarySwitch)stdc++ 
ArLibs                 :=  "Common" "Security_Access_Control" "avrocpp" "zmq" "SQLiteCpp" "sqlite3" "pthread" "log4cpp" "c" "stdc++" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/local/lib $(LibraryPathSwitch)../Common/bin/Debug $(LibraryPathSwitch)../Security_Access_Control/bin/Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -std=c++11 -Wall -fexceptions -Weffc++ $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
LD_LIBRARY_PATH:=$LD_LIBRARY_PATH:/home/alberto/Projects/01_gs4cubesat/C++Server/Common/bin/Debug:/home/alberto/Projects/01_gs4cubesat/C++Server/Security_Access_Control/bin/Debug
FC:=gfortran
FCFLAGS:=
FLFLAGS:=
LinkerName:=$(FC)
Objects0=$(IntermediateDirectory)/src_modules_OrbPropag.f90$(ObjectSuffix) $(IntermediateDirectory)/src_orbpropag_ModuleManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_zmq_fortran_lib.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_orbpropag_main.cpp$(ObjectSuffix) 



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
	@echo Executing Pre Build commands ...
	
	@echo Done


##
## Objects
##
$(IntermediateDirectory)/src_modules_OrbPropag.f90$(ObjectSuffix): src/modules/OrbPropag.f90 
	$(FC) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/OrbPropag/src/modules/OrbPropag.f90" $(FCFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_modules_OrbPropag.f90$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_modules_OrbPropag.f90$(PreprocessSuffix): src/modules/OrbPropag.f90
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_modules_OrbPropag.f90$(PreprocessSuffix) src/modules/OrbPropag.f90

$(IntermediateDirectory)/src_orbpropag_ModuleManager.cpp$(ObjectSuffix): src/orbpropag_ModuleManager.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/OrbPropag/src/orbpropag_ModuleManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_orbpropag_ModuleManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_orbpropag_ModuleManager.cpp$(PreprocessSuffix): src/orbpropag_ModuleManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_orbpropag_ModuleManager.cpp$(PreprocessSuffix) src/orbpropag_ModuleManager.cpp

$(IntermediateDirectory)/src_zmq_fortran_lib.cpp$(ObjectSuffix): src/zmq_fortran_lib.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/OrbPropag/src/zmq_fortran_lib.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_zmq_fortran_lib.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_zmq_fortran_lib.cpp$(PreprocessSuffix): src/zmq_fortran_lib.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_zmq_fortran_lib.cpp$(PreprocessSuffix) src/zmq_fortran_lib.cpp

$(IntermediateDirectory)/src_orbpropag_main.cpp$(ObjectSuffix): src/orbpropag_main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/OrbPropag/src/orbpropag_main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_orbpropag_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_orbpropag_main.cpp$(PreprocessSuffix): src/orbpropag_main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_orbpropag_main.cpp$(PreprocessSuffix) src/orbpropag_main.cpp

##
## Clean
##
clean:
	$(RM) -r ./obj/Debug/



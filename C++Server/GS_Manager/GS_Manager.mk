##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=GS_Manager
ConfigurationName      :=Debug
WorkspacePath          :=/run/user/1000/gvfs/sftp:host=192.168.1.60,user=remote/D:/alberto/Documents/01_gs4cubesat
ProjectPath            :=/run/user/1000/gvfs/sftp:host=192.168.1.60,user=remote/D:/alberto/Documents/01_gs4cubesat/C++Server/GS_Manager
IntermediateDirectory  :=./obj/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alberto
Date                   :=07/05/19
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
ObjectsFileList        :="GS_Manager.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)include $(IncludeSwitch)include/messages $(IncludeSwitch)../Common/include $(IncludeSwitch)../Security_Access_Control/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)Common $(LibrarySwitch)Security_Access_Control $(LibrarySwitch)avrocpp $(LibrarySwitch)pthread $(LibrarySwitch)zmq $(LibrarySwitch)boost_system $(LibrarySwitch)SQLiteCpp $(LibrarySwitch)sqlite3 $(LibrarySwitch)log4cpp 
ArLibs                 :=  "Common" "Security_Access_Control" "avrocpp" "pthread" "zmq" "boost_system" "SQLiteCpp" "sqlite3" "log4cpp" 
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
LD_LIBRARY_PATH:=$LD_LIBRARY_PATH:/run/user/1000/gvfs/sftp:host=192.168.1.60,user=remote/D:/alberto/Documents/01_gs4cubesat/C++Server/Common/bin/Debug:/run/user/1000/gvfs/sftp:host=192.168.1.60,user=remote/D:/alberto/Documents/01_gs4cubesat/C++Server/Security_Access_Control/bin/Debug
Objects0=$(IntermediateDirectory)/src_messages_AddGsnMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_ConnectGsnMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_GsConnectionManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_GetGsnMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_RemoveGsnMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_GsTcpConnection.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_DisconnectGsnMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_GsMessageProcessor.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_gs_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_GsModuleManager.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/src_GsDatabase.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_GsConnection.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/src_messages_AddGsnMessage.cpp$(ObjectSuffix): src/messages/AddGsnMessage.cpp $(IntermediateDirectory)/src_messages_AddGsnMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/run/user/1000/gvfs/sftp:host=192.168.1.60,user=remote/D:/alberto/Documents/01_gs4cubesat/C++Server/GS_Manager/src/messages/AddGsnMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_AddGsnMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_AddGsnMessage.cpp$(DependSuffix): src/messages/AddGsnMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_AddGsnMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_AddGsnMessage.cpp$(DependSuffix) -MM src/messages/AddGsnMessage.cpp

$(IntermediateDirectory)/src_messages_AddGsnMessage.cpp$(PreprocessSuffix): src/messages/AddGsnMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_AddGsnMessage.cpp$(PreprocessSuffix) src/messages/AddGsnMessage.cpp

$(IntermediateDirectory)/src_messages_ConnectGsnMessage.cpp$(ObjectSuffix): src/messages/ConnectGsnMessage.cpp $(IntermediateDirectory)/src_messages_ConnectGsnMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/run/user/1000/gvfs/sftp:host=192.168.1.60,user=remote/D:/alberto/Documents/01_gs4cubesat/C++Server/GS_Manager/src/messages/ConnectGsnMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_ConnectGsnMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_ConnectGsnMessage.cpp$(DependSuffix): src/messages/ConnectGsnMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_ConnectGsnMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_ConnectGsnMessage.cpp$(DependSuffix) -MM src/messages/ConnectGsnMessage.cpp

$(IntermediateDirectory)/src_messages_ConnectGsnMessage.cpp$(PreprocessSuffix): src/messages/ConnectGsnMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_ConnectGsnMessage.cpp$(PreprocessSuffix) src/messages/ConnectGsnMessage.cpp

$(IntermediateDirectory)/src_GsConnectionManager.cpp$(ObjectSuffix): src/GsConnectionManager.cpp $(IntermediateDirectory)/src_GsConnectionManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/run/user/1000/gvfs/sftp:host=192.168.1.60,user=remote/D:/alberto/Documents/01_gs4cubesat/C++Server/GS_Manager/src/GsConnectionManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_GsConnectionManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_GsConnectionManager.cpp$(DependSuffix): src/GsConnectionManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_GsConnectionManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_GsConnectionManager.cpp$(DependSuffix) -MM src/GsConnectionManager.cpp

$(IntermediateDirectory)/src_GsConnectionManager.cpp$(PreprocessSuffix): src/GsConnectionManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_GsConnectionManager.cpp$(PreprocessSuffix) src/GsConnectionManager.cpp

$(IntermediateDirectory)/src_messages_GetGsnMessage.cpp$(ObjectSuffix): src/messages/GetGsnMessage.cpp $(IntermediateDirectory)/src_messages_GetGsnMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/run/user/1000/gvfs/sftp:host=192.168.1.60,user=remote/D:/alberto/Documents/01_gs4cubesat/C++Server/GS_Manager/src/messages/GetGsnMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_GetGsnMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_GetGsnMessage.cpp$(DependSuffix): src/messages/GetGsnMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_GetGsnMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_GetGsnMessage.cpp$(DependSuffix) -MM src/messages/GetGsnMessage.cpp

$(IntermediateDirectory)/src_messages_GetGsnMessage.cpp$(PreprocessSuffix): src/messages/GetGsnMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_GetGsnMessage.cpp$(PreprocessSuffix) src/messages/GetGsnMessage.cpp

$(IntermediateDirectory)/src_messages_RemoveGsnMessage.cpp$(ObjectSuffix): src/messages/RemoveGsnMessage.cpp $(IntermediateDirectory)/src_messages_RemoveGsnMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/run/user/1000/gvfs/sftp:host=192.168.1.60,user=remote/D:/alberto/Documents/01_gs4cubesat/C++Server/GS_Manager/src/messages/RemoveGsnMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_RemoveGsnMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_RemoveGsnMessage.cpp$(DependSuffix): src/messages/RemoveGsnMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_RemoveGsnMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_RemoveGsnMessage.cpp$(DependSuffix) -MM src/messages/RemoveGsnMessage.cpp

$(IntermediateDirectory)/src_messages_RemoveGsnMessage.cpp$(PreprocessSuffix): src/messages/RemoveGsnMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_RemoveGsnMessage.cpp$(PreprocessSuffix) src/messages/RemoveGsnMessage.cpp

$(IntermediateDirectory)/src_GsTcpConnection.cpp$(ObjectSuffix): src/GsTcpConnection.cpp $(IntermediateDirectory)/src_GsTcpConnection.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/run/user/1000/gvfs/sftp:host=192.168.1.60,user=remote/D:/alberto/Documents/01_gs4cubesat/C++Server/GS_Manager/src/GsTcpConnection.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_GsTcpConnection.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_GsTcpConnection.cpp$(DependSuffix): src/GsTcpConnection.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_GsTcpConnection.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_GsTcpConnection.cpp$(DependSuffix) -MM src/GsTcpConnection.cpp

$(IntermediateDirectory)/src_GsTcpConnection.cpp$(PreprocessSuffix): src/GsTcpConnection.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_GsTcpConnection.cpp$(PreprocessSuffix) src/GsTcpConnection.cpp

$(IntermediateDirectory)/src_messages_DisconnectGsnMessage.cpp$(ObjectSuffix): src/messages/DisconnectGsnMessage.cpp $(IntermediateDirectory)/src_messages_DisconnectGsnMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/run/user/1000/gvfs/sftp:host=192.168.1.60,user=remote/D:/alberto/Documents/01_gs4cubesat/C++Server/GS_Manager/src/messages/DisconnectGsnMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_DisconnectGsnMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_DisconnectGsnMessage.cpp$(DependSuffix): src/messages/DisconnectGsnMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_DisconnectGsnMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_DisconnectGsnMessage.cpp$(DependSuffix) -MM src/messages/DisconnectGsnMessage.cpp

$(IntermediateDirectory)/src_messages_DisconnectGsnMessage.cpp$(PreprocessSuffix): src/messages/DisconnectGsnMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_DisconnectGsnMessage.cpp$(PreprocessSuffix) src/messages/DisconnectGsnMessage.cpp

$(IntermediateDirectory)/src_GsMessageProcessor.cpp$(ObjectSuffix): src/GsMessageProcessor.cpp $(IntermediateDirectory)/src_GsMessageProcessor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/run/user/1000/gvfs/sftp:host=192.168.1.60,user=remote/D:/alberto/Documents/01_gs4cubesat/C++Server/GS_Manager/src/GsMessageProcessor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_GsMessageProcessor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_GsMessageProcessor.cpp$(DependSuffix): src/GsMessageProcessor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_GsMessageProcessor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_GsMessageProcessor.cpp$(DependSuffix) -MM src/GsMessageProcessor.cpp

$(IntermediateDirectory)/src_GsMessageProcessor.cpp$(PreprocessSuffix): src/GsMessageProcessor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_GsMessageProcessor.cpp$(PreprocessSuffix) src/GsMessageProcessor.cpp

$(IntermediateDirectory)/src_gs_main.cpp$(ObjectSuffix): src/gs_main.cpp $(IntermediateDirectory)/src_gs_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/run/user/1000/gvfs/sftp:host=192.168.1.60,user=remote/D:/alberto/Documents/01_gs4cubesat/C++Server/GS_Manager/src/gs_main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_gs_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_gs_main.cpp$(DependSuffix): src/gs_main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_gs_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_gs_main.cpp$(DependSuffix) -MM src/gs_main.cpp

$(IntermediateDirectory)/src_gs_main.cpp$(PreprocessSuffix): src/gs_main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_gs_main.cpp$(PreprocessSuffix) src/gs_main.cpp

$(IntermediateDirectory)/src_GsModuleManager.cpp$(ObjectSuffix): src/GsModuleManager.cpp $(IntermediateDirectory)/src_GsModuleManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/run/user/1000/gvfs/sftp:host=192.168.1.60,user=remote/D:/alberto/Documents/01_gs4cubesat/C++Server/GS_Manager/src/GsModuleManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_GsModuleManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_GsModuleManager.cpp$(DependSuffix): src/GsModuleManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_GsModuleManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_GsModuleManager.cpp$(DependSuffix) -MM src/GsModuleManager.cpp

$(IntermediateDirectory)/src_GsModuleManager.cpp$(PreprocessSuffix): src/GsModuleManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_GsModuleManager.cpp$(PreprocessSuffix) src/GsModuleManager.cpp

$(IntermediateDirectory)/src_GsDatabase.cpp$(ObjectSuffix): src/GsDatabase.cpp $(IntermediateDirectory)/src_GsDatabase.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/run/user/1000/gvfs/sftp:host=192.168.1.60,user=remote/D:/alberto/Documents/01_gs4cubesat/C++Server/GS_Manager/src/GsDatabase.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_GsDatabase.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_GsDatabase.cpp$(DependSuffix): src/GsDatabase.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_GsDatabase.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_GsDatabase.cpp$(DependSuffix) -MM src/GsDatabase.cpp

$(IntermediateDirectory)/src_GsDatabase.cpp$(PreprocessSuffix): src/GsDatabase.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_GsDatabase.cpp$(PreprocessSuffix) src/GsDatabase.cpp

$(IntermediateDirectory)/src_GsConnection.cpp$(ObjectSuffix): src/GsConnection.cpp $(IntermediateDirectory)/src_GsConnection.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/run/user/1000/gvfs/sftp:host=192.168.1.60,user=remote/D:/alberto/Documents/01_gs4cubesat/C++Server/GS_Manager/src/GsConnection.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_GsConnection.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_GsConnection.cpp$(DependSuffix): src/GsConnection.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_GsConnection.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_GsConnection.cpp$(DependSuffix) -MM src/GsConnection.cpp

$(IntermediateDirectory)/src_GsConnection.cpp$(PreprocessSuffix): src/GsConnection.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_GsConnection.cpp$(PreprocessSuffix) src/GsConnection.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./obj/Debug/



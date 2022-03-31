! 
!   CubeGS
!   An online Ground Segment for Cubesats and Small Sats
!   (c) 2019 Incomplete Worlds
!    

module OrbPropag

  !use, intrinsic :: ISO_C_Binding, only: C_int, C_double
  !use, intrinsic :: ISO_C_Binding, only: C_ptr, C_NULL_ptr
  use iso_c_binding, only : C_CHAR, C_NULL_CHAR, C_INT

  implicit none
  

  ! API for sending and receiving messages from the FDS via ZeroMQ
  ! All data reading and writing into the database should be made via this API
  !
  interface
    subroutine send_message_c ( messageCode, inputMessage, outputMessage ) bind ( C, name = "send_message_c" )
      use iso_c_binding, only : C_CHAR, C_INT
      integer ( kind = C_INT ) :: messageCode
      character ( kind = C_CHAR ) :: inputMessage ( * )
      character ( kind = C_CHAR ) :: outputMessage ( * )
    end subroutine send_message_c
  end interface

  interface
    subroutine receive_message_c ( string ) bind ( C, name = "receive_message_c" )
      use iso_c_binding, only : C_CHAR
      character ( kind = C_CHAR ) :: string ( * )
    end subroutine receive_message_c
  end interface

  interface
    subroutine return_c ( inErrorCode, inErrorMessage ) bind ( C, name = "return_c" )
      use iso_c_binding, only : C_INT, C_CHAR
      integer ( kind = C_INT ) :: inErrorCode
      character ( kind = C_CHAR ) :: inErrorMessage
    end subroutine return_c
  end interface
  
  ! Test
  interface
    subroutine print_c ( inMessage ) bind ( C, name = "print_c" )
      use iso_c_binding, only : C_CHAR
      character ( kind = C_CHAR ) :: inMessage ( * )
    end subroutine print_c
  end interface

contains

  !
  !  FORTRAN Main 
  ! 
  subroutine FortranMain() bind(C, name="fortranMain")

    implicit none
    
    character*256   outputMessage
    character*4096  answerData


    write (*,*) "This is the main entry point of a Fortran Module"
  
    ! Call a C Function
    call print_c( C_CHAR_"Hello World! from Fortran" // C_NULL_CHAR )
     
    ! Send the return code
    ! CODE_REPLY_MESSAGE = 10
    !
    ! outputMessage = C_CHAR_"{ \\
    !     \"msgCode\" : \"10\", \\
    !     \"errorCode\" : \"0\", \\
    !     \"errorMessage\" : \"\" \\
    !     }" // C_NULL_CHAR
     call send_message_c(10, outputMessage, answerData)
    
    ! Send the return code
    call return_c(0, C_CHAR_"" // C_NULL_CHAR)
  end subroutine FortranMain

end module OrbPropag


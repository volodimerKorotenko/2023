#pragma once

int Factorial( int Number );
int exponentiation( int RaisedToPower, int degree );
int Sum( int ( *Formula )( int, int ), int NumberOfTimes,int A = 0, int n = 0);
int ABS( int Number );
int GetInt( int Max, const char Message[] );
void ChoiceOfOption( int option );
void Menu( char Menu[][103], int Heaght );
void CallMenu();
int Formula_1( int Counter, int buff = 0 );
int Formula_2( int Counter, int buff = 0);
int Formula_3( int Counter, int );
int Formula_4( int Counter, int );
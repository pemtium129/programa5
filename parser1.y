%{
#include <stdio.h>
int tipo;
extern int yylex();
void yyerror(char *s);
int typeGBL;
int baseGBL;
int dir = 0;
void init();
%}

%union{
    int tipo;
    char id[32];
    char cadena[100];
    char caracter[1];
    int num;
}

 // Fecha: 23/05/2020
 // Autor: VMCR
 // Descripción: Declaración de los tokens para análisis sintáctico
 // Modificación: 24/05/20
 // Modificó: ULM, JRA, DAOA
 // Modificación: 25/05/20
 // Modificó: ULM


%token<id>  ID
%token<num> NUM
%token<cadena> STRING
%token<caracter> CHAR
%token  START END
%token  INT FLOAT DOUBLE CHAR VOID STRUCT
%token  COLON COMMA WHILE DO PRINT SCAN PRED
%token  RETURN SWITCH BREAK CASE DEF DEFAULT SEMICOLON POINT
%token  TRUE FALSE
%right  ASSIGN
%left   OR
%left   AND
%left   EQUAL NOTEQUAL
%left   GREATER LESS LT GT
%left   PLUS MINUS
%left   MUL DIV MOD
%left   NOT
%nonassoc   LPAR RPAR LSQBRACK RSQBRACK
%left IF THEN
%nonassoc   SIT 
%nonassoc   ELSE

%start programa

 // Fecha: 24/05/2020
 // Autor: VMCR
 // Descripción: Representación de la gramática
 // Modificación: 24/05/20
 // Modificó: ULM, JRA, DAOA, VMCR
 // Modificación: 25/05/20
 // Modificó: ULM
// Modificación: 22/06/20
 // Modificó: ULM
%%

programa :{
            init();
        } declaraciones{ 
            imprimir(&simbolos);
            imprimirType(&tipos);
        } funciones;

declaraciones : tipo{
                    typeGBL = $1 ;
                } lista_var SEMICOLON declaraciones
            | tipo_registro{
                    typeGBL = $1 ;
                } lista_var SEMICOLON declaraciones
            | ;

tipo_registro : STRUCT START declaraciones END;

tipo : base{
                baseGBL=$1
            } tipo_arreglo{$$.type=$2.type};

base : INT{$$=0}
    | FLOAT{$$=1}
    | DOUBLE{$$=2}
    | CHAR{$$=3}
    | VOID{$$=4};

tipo_arreglo : LSQBRACK NUM RSQBRACK tipo_arreglo{if($2.type=0)
                                                    if($2.dir>0)
                                                        $$.type=STT.getTop().insert(’array’,$2, $$.type);
                                                    ELSE
                                                        printf('error')
                                                  else
                                                    printf('error')
                                                    }
            | {$$.type = typeGBL};

lista_var : lista_var COMMA ID{if(!getID(&simbolos, $1))
                                    yyerror("El id no fue declarado");                
                                };
            | ID{
                if(!getID(&simbolos, $1))
                    yyerror("El id no fue declarado");                
            };     

funciones : DEF tipo ID LPAR argumentos RPAR START declaraciones sentencias END funciones
            | ;

argumentos : lista_arg{$$.lista_arg=$1.lista_arg;
                       $$.num=$1.num}
            | VOID{$$.lista_arg = Null;
                   $$.num=0};

lista_arg : lista_arg{$$.lista_arg=$1.lista_arg} 
            COMMA arg{$$.lista.append($3.type)
                      $$.num = $1.num + 1}
            | {$$.lista = newList()}arg{$$.lista.append($1.type) 
                                        $$.num = 1};


arg : tipo_arg ID{if(!getID(&simbolos, $1))
                    yyerror("El id no fue declarado");                
                 };

tipo_arg : base{baseGBL=$1.base} param_arr{tipo.type=$2.type};

param_arr : LSQBRACK RSQBRACK param_arr{$$.type = STT.getTop().insert(’array', 0, $3.tipo)}
            | {$$.type=baseGBL};

sentencias : sentencias sentencia
            |sentencia;

sentencia : IF e_bool THEN sentencia END %prec SIT
            | IF e_bool THEN sentencia ELSE sentencia END
            | WHILE e_bool DO sentencia END
            | DO sentencia WHILE e_bool SEMICOLON
            | SWITCH LPAR variable RPAR DO casos predeterminado END
            | variable ASSIGN expresion SEMICOLON
                {dir = reducir(expresion.dir, epresion.type, variable.type)
                 if($1.code_est = true)
                    genCode($1.base[$1.des] = dir)
                 else
                    genCode(v$1.dir = dir)
                 }
            | PRINT expresion SEMICOLON{printf('%s',$2.dir)}
            | SCAN variable SEMICOLON
            | RETURN SEMICOLON {RETURN}
            | RETURN expresion SEMICOLON {RETURN $2.dir;}
            | BREAK SEMICOLON{index = newIndex() 
                              $$.nextlist = newIndexList(index) 
                              genCode(”goto” index)}
            | START sentencias{$$.nextlist = $2.nextlist} END;

casos : CASE NUM COLON sentencia casos
	| CASE NUM COLON sentencia;

predeterminado : PRED COLON sentencia
                | {$$.prueba = Null };

e_bool : e_bool OR e_bool %prec SIT
        | e_bool AND e_bool
        | NOT e_bool{$$.truelist = $2.falselist
                     $$.falselist = $$.truelist}
        | LPAR e_bool RPAR
        | relacional{$$.truelist = $1.truelist
                     $$.falselist = $1.falselist}
        | TRUE{index0 = newIndex() 
               $$.truelist = newIndexList(index0) 
               genCode(’goto’ index0)}
        | FALSE{index0 = newIndex()
               $$.falselist = newIndexList(index0)
               genCode(’goto’ index0)};

relacional : relacional GREATER relacional{index0 = newIndex()
                                           index1 = newIndex()
                                           $$.truelist = newIndexList(index0)
                                           $$.falselist = newIndexList(index1)
                                           if($1.dir > $3) 
                                            ’goto’ index0
                                           else
                                            'goto’ index1)}
            | relacional LESS relacional{index0 = newIndex()
                                           index1 = newIndex()
                                           $$.truelist = newIndexList(index0)
                                           $$.falselist = newIndexList(index1)
                                           if($1.dir < $3) 
                                            ’goto’ index0
                                           else
                                            'goto’ index1)}
            | relacional LT relacional{index0 = newIndex()
                                           index1 = newIndex()
                                           $$.truelist = newIndexList(index0)
                                           $$.falselist = newIndexList(index1)
                                           if($1.dir <= $3) 
                                            ’goto’ index0
                                           else
                                            'goto’ index1)}
            | relacional GT relacional{index0 = newIndex()
                                           index1 = newIndex()
                                           $$.truelist = newIndexList(index0)
                                           $$.falselist = newIndexList(index1)
                                           if($1.dir >= $3) 
                                            ’goto’ index0
                                           else
                                            'goto’ index1)}
            | relacional NOTEQUAL relacional{index0 = newIndex()
                                           index1 = newIndex()
                                           $$.truelist = newIndexList(index0)
                                           $$.falselist = newIndexList(index1)
                                           if($1.dir <> $3) 
                                            ’goto’ index0
                                           else
                                            'goto’ index1)}
            | relacional EQUAL relacional{index0 = newIndex()
                                           index1 = newIndex()
                                           $$.truelist = newIndexList(index0)
                                           $$.falselist = newIndexList(index1)
                                           if($1.dir == $3) 
                                            ’goto’ index0
                                           else
                                            'goto’ index1)}
            | expresion{$$.dir = $1.dir 
                        $$.tipo = $1.tipo};;

expresion : expresion oparit expresion %prec SIT
            |expresion PLUS expresion{                   
                    char dir1[32], dir2[32]; 
                    newTemp($$.dir);
                    $$.tipo = max($1.tipo, $3.tipo);
                    ampliar(dir1, $1.dir, $1.tipo, $$.tipo);
                    ampliar(dir2, $3.dir, $3.tipo, $$.tipo);
                    printf("%s = %s + %s\n", $$.dir, dir1, dir2);
                }
            |expresion MINUS expresion{                   
                    char dir1[32], dir2[32]; 
                    newTemp($$.dir);
                    $$.tipo = max($1.tipo, $3.tipo);
                    ampliar(dir1, $1.dir, $1.tipo, $$.tipo);
                    ampliar(dir2, $3.dir, $3.tipo, $$.tipo);
                    printf("%s = %s - %s\n", $$.dir, dir1, dir2);
                }
             |expresion MUL expresion{                   
                    char dir1[32], dir2[32]; 
                    newTemp($$.dir);
                    $$.tipo = max($1.tipo, $3.tipo);
                    ampliar(dir1, $1.dir, $1.tipo, $$.tipo);
                    ampliar(dir2, $3.dir, $3.tipo, $$.tipo);
                    printf("%s = %s * %s\n", $$.dir, dir1, dir2);
                }
            |expresion DIV expresion{                   
                    char dir1[32], dir2[32]; 
                    newTemp($$.dir);
                    $$.tipo = max($1.tipo, $3.tipo);
                    ampliar(dir1, $1.dir, $1.tipo, $$.tipo);
                    ampliar(dir2, $3.dir, $3.tipo, $$.tipo);
                    printf("%s = %s / %s\n", $$.dir, dir1, dir2);
                }
            |expresion MOD expresion{                   
                    char dir1[32], dir2[32]; 
                    newTemp($$.dir);
                    $$.tipo = max($1.tipo, $3.tipo);
                    ampliar(dir1, $1.dir, $1.tipo, $$.tipo);
                    ampliar(dir2, $3.dir, $3.tipo, $$.tipo);
                    printf("%s = %s '%' %s\n", $$.dir, dir1, dir2);
                }
            | LPAR expresion RPAR{$$.type = $2.type
                                  $$.dir = $2.dir}
            | ID
            | variable {$$.type = $1.type 
                        e$$.dir = $1.dir}
            | NUM{$$.type = num.type;
                  $$.dir = num.dir;}
            | STRING{$$.type = 4(?)
                    if(TablaCadenas.existe($1))
                        $$.dir= TablaCadena.getIndexStr($1)
                    else
                        $$.dir= TalbaCadena.insert($1)
                    }
            | CHAR{$$.type = 3
                    if(TablaCadenas.existe($1))
                        $$.dir= TablaCadena.getIndexStr($1)
                    else
                        $$.dir= TalbaCadena.insert($1)
                    };


variable : ID variable_comp

variable_comp: dato_est_sim{$$.type = $1.type
                        $$.des = $1.des
                        $$.code_est = $1.code_est}
        | arreglo{$$.type = $1.type 
                  $$.des = $1.dir 
                  $$.code_est = true}
        | ID LPAR parametros RPAR;

dato_est_sim : dato_est_sim POINT ID
            | ;

arreglo : LSQBRACK expresion RSQBRACK
        | arreglo LSQBRACK expresion RSQBRACK;

parametros : lista_param{$$.lista = $1.lista
                         $$.num = $1.num}
            | {$$.lista = NULO
               $$.num = 0};

lista_param : lista_param{$$.lista = $1.lista} COMMA expresion{$$.lista.append($3.type)
                                                               $$.num = $1 + 1};
            |expresion{$$.lista = newList()
                       $$.lista.append($1.type)
                       $$.num = 1}

%%
/*Código de usuario, aquí se despliega un mensaje si se encuentra un error sintáctico*/
void yyerror(char *s){
    printf("Error sintáctico: %s\n");
}

void init(){
    TYPE tint, tfloat;
    tipos.num = 0;
    simbolos.num =0;
    
    tint.id  = 0;
    strcpy(tint.nombre, "int");
    tint.tam = 4;

    tfloat.id  = 1;
    strcpy(tfloat.nombre, "float");
    tfloat.tam = 4;

    insertarType(&tipos, tint);
    insertarType(&tipos, tfloat);
}
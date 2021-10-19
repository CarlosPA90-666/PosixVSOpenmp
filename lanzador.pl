#!/usr/bin/perl

#Fichero para automatizacion de ejecucion por lotes de un ejecutable
#Dado parametro de entrada


#----------------------------POSIX-----------------------------


$repeticiones3 = 1;
@ejecutables3 = ("POSIX");
@matrizSize3 = ("400","600","800","1000","1500","2000","2500","3000");
@threads = ("1","4","8","16");
$path3 = "/media/carlos/Disco\  Duro\  2/Universidad/Computacion\  Paralela/Parcial2/";

foreach $exe3 (@ejecutables3){
    foreach $size3 (@matrizSize3){
        foreach $thread3 (@threads){

            $fichero3 = "$path3"."solucionesPOSIX/"."$exe3"."-size"."$size3"."-Threads"."$thread3.csv";

            #$fichero3 = "$path3"."soluciones3/"."$exe3"."-Threads"."$thread3"."-size"."$size3.csv";
            print("$fichero3\n");
            for($i=0; $i<$repeticiones3; $i++){
            #print("$path3$exe3 $size3 \n");
            system("$path3$exe3 $size3 $thread3 >> $fichero3");
            }

        }

    }
}

exit(1);

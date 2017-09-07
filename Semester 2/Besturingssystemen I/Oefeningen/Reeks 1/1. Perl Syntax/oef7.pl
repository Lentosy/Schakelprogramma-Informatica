$floatingpoint1 = 3.14159265;
$floatingpoint2 = 3.14394312;



if(sprintf "%.2f", $floatingpoint1 eq sprintf "%2.f", $floatingpoint2){
  print "numbers are equal";
}else{
  print "numbers are not equal";
}

print "\n";

@array = map { $_ * 5 }1..100;

print uc "full:\n", join " ", @array, "\n";

@front = splice @array, 0 , 50;
@end = splice @array, -50;

print uc "front:\n", join " ", @front , "\n";

print uc "end:\n", join " ", @end, "\n";

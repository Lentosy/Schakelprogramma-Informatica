@A = (
  [2, 3, 4],
  [4, 0 ,3]
);

@B = (
  [0, 6],
  [4, 2],
  [2, 4]
);

@C = ();

$arows = @A;
$acols = @{$A[0]};
$brows = @B;
$bcols = @{$B[0]};


die "$bcols does not match $arows" if $bcols != $arows;

for $i (0 .. ($arows - 1)){
  for $j (0 .. ($bcols - 1)){
    for $k (0 .. ($acols - 1)){
      $C[$i][$j] += $A[$i][$k] * $B[$k][$j];
    }
    printf "%4d", $C[$i][$j];
  }
  print "\n";
}

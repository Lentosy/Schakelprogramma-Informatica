#dag, maand, jaar


($mday, $mon, $year , $yday) = (localtime)[3..5, 7];

printf "%d/%d/%d in week %d\n", $mday, $mon + 1 , $year += 1900, int $yday / 7;

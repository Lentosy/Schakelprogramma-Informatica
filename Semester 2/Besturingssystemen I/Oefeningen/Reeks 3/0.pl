%gewesten=( "Antwerpen"      => "Vlaanderen", "Henegouwen"   => "Wallonie",
          "Limburg"        => "Vlaanderen", "Namen"        => "Wallonie",
          "Oost-Vlaanderen"=> "Vlaanderen", "Luik"         => "Wallonie",
          "Vlaams-Brabant" => "Vlaanderen", "Luxemburg"    => "Wallonie",
          "West-Vlaanderen"=> "Vlaanderen", "Waals-Brabant"=> "Wallonie");

%provincies=( "Aalst"       => "Oost-Vlaanderen", "Brugge"  => "West-Vlaanderen",
             "Dendermonde" => "Oost-Vlaanderen", "Ieper"   => "West-Vlaanderen",
             "Eeklo"       => "Oost-Vlaanderen", "Oostende"=> "West-Vlaanderen",
             "Oudenaarde"  => "Oost-Vlaanderen", "Kortrijk"=> "West-Vlaanderen",
             "Sint-Niklaas"=> "Oost-Vlaanderen", "Gent"    => "Oost-Vlaanderen",
             "Halle"       => "Vlaams-Brabant" , "Genk"    => "Limburg"        ,
             "Leuven"      => "Vlaams-Brabant" , "Hasselt" => "Limburg"        ,
             "Vilvoorde"   => "Vlaams-Brabant" , "Tongeren"=> "Limburg"        );

%steden = ();

while(($stad, $provincie) = each %provincies){
	push @{$steden{$gewesten{$provincie}}{$provincie}}, $stad;

}

for $gewest (keys %steden){
	print "$gewest\n";
	for $provincie (keys %{$steden{$gewest}}){
		print "\t$provincie\n";
		for $stad (@{$steden{$gewest}{$provincie}}){
			print "\t\t$stad\n";
		}
	}
}

# print ? steden{"Vlaanderen"} ?
print join "\n", map{@{$_}} values %{$steden{"Vlaanderen"}};

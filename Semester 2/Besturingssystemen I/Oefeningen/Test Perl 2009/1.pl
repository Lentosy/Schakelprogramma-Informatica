# Naam student: Bert De Saffel
#
# Status implementatie:
#   berekening sleutelcomponent x ? 
#   berekening sleutelcomponent y ? 
#   sortering atp lijst ? 
#   vervanging numerieke id's in rooster ? 
#   reproductie lege lijnen en streepjeslijnen ? 
#   aanvulling nationaliteit met ranking ? 
#   alignering links en rechts ? 
#
# Eventuele tekortkomingen: 
#

%spelers; # De verzameling van alle tennisspelers

my $x = 0; # De startwaarde van het sleutelcomponent x
while (<DATA>) {
  chomp;
  
  # Extractie spelers
  if(m/
	( # Extractie naam
	  [\w]+ # Voornaam
	  (?:[\s-][\w]+)* # Een voornaam wordt gevolgd door ofwel een spatie of door een - met daarna een andere naam
	)
	\s # Er is een spatie tussen de naam en de nationaliteit

	\(( # Extractie nationaliteit
	  [A-Z]{3} # Een nationaliteit bestaat uit 3 hoofdletters
	)\)
      /x){

    $spelers{$.}->{naam} = $1;
    $spelers{$.}->{nationaliteit} = $2;
    # Bepalen sleutelcomponent x
    $spelers{$.}->{x} = $x;
    $x++ if 2 ** $x == $.;
    # Bepalen sleutelcomponent y
    # ?? random ??


    next; # De volgende conditie waarbij gecontroleerd wordt op roostergegevens kan nooit waar zijn als de huidige lijn een tennisspeler is
  }

  # Extractie roostergegevens
  if(m/
       (\d+)\s*(\d+) # Een getal gevolgd door een willekeurig aantal spaties en dan terug een getal
      /x){

    # Uitprinten roosterlijn
    printf "%-32s", $spelers{$1}->{naam} . " (" . $spelers{$1}->{nationaliteit} . ",$1)";
    printf "%32s", $spelers{$2}->{naam}  . " (" . $spelers{$2}->{nationaliteit} . ")";
    print "\n";
    
  }else{
    # Deze lijn is tot slot een reeks van spaties of een reeks van streepjes
    print "$_\n";
  }
}

__DATA__
Roger Federer (SUI)
Rafael Nadal (ESP)
Novak Djokovic (SRB)
Andy Murray (GBR)
Juan Martin Del Potro (ARG)
Nikolay Davydenko (RUS)
Andy Roddick (USA)
Jo-Wilfried Tsonga (FRA)
Fernando Verdasco (ESP)
Robin Soderling (SWE)
Fernando Gonzalez (CHI)
Gilles Simon (FRA)
Marin Cilic (CRO)
Radek Stepanek (CZE)
Gael Monfils (FRA)
Tommy Robredo (ESP)
Tommy Haas (GER)
David Ferrer (ESP)
Tomas Berdych (CZE)
Lleyton Hewitt (AUS)
Stanislas Wawrinka (SUI)
Juan Carlos Ferrero (ESP)
James Blake (USA)
Philipp Kohlschreiber (GER)
Mikhail Youzhny (RUS)
Sam Querrey (USA)
David Nalbandian (ARG)
Nicolas Almagro (ESP)
Ivan Ljubicic (CRO)
Juan Monaco (ARG)
Viktor Troicki (SRB)
Jeremy Chardy (FRA)
Paul-Henri Mathieu (FRA)
Andreas Beck (GER)
Jurgen Melzer (AUT)
Albert Montanes (ESP)
Victor Hanescu (ROU)
Igor Andreev (RUS)
John Isner (USA)
Ivo Karlovic (CRO)
Marcos Baghdatis (CYP)
Dudi Sela (ISR)
Thomaz Bellucci (BRA)
Benjamin Becker (GER)
Feliciano Lopez (ESP)
Janko Tipsarevic (SRB)
Guillermo Garcia-Lopez (ESP)
Jose Acasuso (ARG)
Pablo Cuevas (URU)
Evgeny Korolev (RUS)
Julien Benneteau (FRA)
Andreas Seppi (ITA)
Fabrice Santoro (FRA)
Horacio Zeballos (ARG)
Daniel Koellerer (AUT)
Fabio Fognini (ITA)
Mardy Fish (USA)
Dmitry Tursunov (RUS)
Simon Greul (GER)
Maximo Gonzalez (ARG)
Jan Hernych (CZE)
Olivier Rochus (BEL)
Marc Gicquel (FRA)
Martin Vassallo Arguello (ARG)
1                                                             64
32                                                            33
17                                                            48
16                                                            49

9                                                             56
24                                                            41
25                                                            40
8                                                             57
----------------------------------------------------------------
5                                                             60
28                                                            37
21                                                            44
12                                                            53

13                                                            52
20                                                            45
29                                                            36
4                                                             61
----------------------------------------------------------------
3                                                             62
30                                                            35
19                                                            46
14                                                            51

11                                                            54
22                                                            43
27                                                            38
6                                                             59
----------------------------------------------------------------
7                                                             58
26                                                            39
23                                                            42
10                                                            55

15                                                            50
18                                                            47
31                                                            34
2                                                             63

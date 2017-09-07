@array_numbers = 1..26;
@array_strings = 'a'..'z';

push @array_numbers, @array_strings;

@array = @array_numbers;

print join " ", @array, "\n";

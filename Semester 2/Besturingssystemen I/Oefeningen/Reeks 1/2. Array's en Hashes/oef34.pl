%hash = map { chr $_ => $_ } 65..90;

print map { "$_ => $hash{$_}\n" } keys %hash;

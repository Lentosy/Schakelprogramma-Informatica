%hash = map { $_ => $_ * 10} 1..10;

print "@{[%hash]}\n";

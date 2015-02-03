def encrypt (mes, key)
  mes.each_index do |s|
    mes[s].length.times do |i|
      c = mes[s][i].codepoints.to_a[0].to_i
      if c > 1071 and c < 1104 then c = (c + key - 1072) % 32 + 1072 end
      ('а'..'я').each { |j| if j.codepoints.to_a[0].to_i == c then mes[s][i] = j end}
    end
  end
  return mes
end


def decrypt (mes)
  dict = []
  File.foreach("dictionary.txt") { |line| dict << line[0..line.length - 2]}
  demes =  Marshal.load(Marshal.dump(mes))
  max_count, key = 0
  33.times do |i|
    count = 0
    mes = encrypt(mes, i)
    mes.each  { |s| dict.each { |w| if s == w or s[0..s.length - 2] == w then count += 1 end}}
    if max_count < count then max_count, key = count, i end
    mes =  Marshal.load(Marshal.dump(demes))
  end
  mes = encrypt(mes, key)
  return mes
end



mes = ''
File.foreach("input.txt") {|line| mes << line}

#mes = encrypt(mes.split(' '),  1)
mes = decrypt(mes.split(' '))

$stdout = File.open('output.txt', 'w')
mes.each_index {|i|
  print "#{mes[i]} "
  if i % 10 == 0 then puts end
}


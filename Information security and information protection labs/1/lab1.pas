const e = 10;
const a = 6;
const b = 4;
var
  txt, txt_i:string;
  i, j, z, yardage:integer;
  matrix: array[1..a, 1..b] of integer;
  k1, k2: array [1..e] of integer;
begin
  writeln('Text to encrypt: ', #10); readln(txt);
  yardage:=length(txt);
  if (yardage=a*b) then 
    begin
      writeln('Key to write line by line: ', #10);
      readln(k1[1], k1[2], k1[3], k1[4], k1[5], k1[6]);
      write(#10); z:=0;
      for i:=1 to 5 do
        for j:=i+1 to 6 do
          if (k1[i]=k1[j]) then z:=z+1;
          if (z<>0) then writeln('Key symbols are not unique', #10)
        until z = 0;
      for j:=1 to 4 do
        for i:= 1 to 6 do
          matrix[i, k2[j]]:=txt_i[(j-1)*a+i]; txt:='';
      for i:=1 to 6 do
        for j:=1 to 4 do
          txt:=txt+matrix[k1[i], j];
      writeln('Encrypted: ', #10, txt, #10);
    end
  else write('Error!');
end.
var
  a, b, c, d: string;
  i, j, k, t, q: integer;

begin
  t := 1;
  writeln('Text tot encrypt: ', #10);
  readln(a);
  writeln('Key-word: ');
  readln(d);
  q := length(d);
  c := '';
  b := 'abcdefghijklmnopqrstuvwxyz';
  for i := 1 to length(a) do
    for j := 1 to length(b) do
    begin
      if a[i] = b[j] then
      begin
        if t > length(d) then
          t := 1;
        for k := 1 to length(b) do
        begin
          if d[t] = b[k] then
            q := j + k - 1;
          if q > 26 then
            q := q - 26;
        end;
        c := c + b[q];
        t := t + 1;
      end;
    end;
  writeln('Encrypted: ', c, #10);
  readln;
end.
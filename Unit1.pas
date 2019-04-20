Unit Unit1;

interface

uses System, System.Drawing, System.Windows.Forms;

var columns : array ['A'..'Z'] of DataGridViewColumn;
var M1 : array ['A'..'Z', 'A'..'Z', 0..25] of string; // Матрица путей из i в j
var M2 : array ['A'..'Z', 'A'..'Z', 0..25] of string; // Матрица путей из i в j
var Mn1 : array ['A'..'Z', 'A'..'Z'] of char; // Матрица направлений из i в j


procedure composition(max : char); forward;
procedure deleteNonelementart(max: char); forward;

type
  Form1 = class(Form)
    procedure button1_Click(sender: Object; e: EventArgs);
    procedure numericUpDown1_ValueChanged(sender: Object; e: EventArgs);
    procedure button2_Click(sender: Object; e: EventArgs);
  {$region FormDesigner}
  private
    {$resource Unit1.Form1.resources}
    elementCountBox: NumericUpDown;
    label1: &Label;
    fromBox: NumericUpDown;
    label2: &Label;
    toBox: NumericUpDown;
    label3: &Label;
    dataGridView1: DataGridView;
    richTextBox1: RichTextBox;
    button2: Button;
    button1: Button;
    {$include Unit1.Form1.inc}
  {$endregion FormDesigner}
  public
    constructor;
    begin
      InitializeComponent;
      
      // Создание столбцов 
      for var i : char := 'A' to 'Z' do begin
        columns[i] := new DataGridViewColumn();
        columns[i].HeaderText := i.toString();
        columns[i].Name := i.toString();
        columns[i].CellTemplate := new DataGridViewTextBoxCell();
        columns[i].Width := 25;
        columns[i].ReadOnly := false;
      end;
      
      // Добавление первоначальных столбцов на форму
      var d : char = chr(ord('A')+Decimal.ToInt16(elementCountBox.Value)-1);
      for var i : char := 'A' to (d) do begin
        dataGridView1.Columns.Add(columns[i]);
        dataGridView1.Rows.Add();
      end;
      
      // Запрещаем пользователю добавлять строки
      dataGridView1.AllowUserToAddRows := false; 
    end;
  end;

implementation

procedure Form1.button1_Click(sender: Object; e: EventArgs);
begin
  var iMax : char = chr(ord('A') + Decimal.ToInt16(elementCountBox.Value)-1);
  var jMax : char = chr(ord('A') + Decimal.ToInt16(elementCountBox.Value)-1);
  
  var fromel : char = chr(ord('A') + Decimal.ToInt16(fromBox.Value)-1);
  var toel : char = chr(ord('A') + Decimal.ToInt16(toBox.Value)-1);
  
  for i : char := 'A' to iMax do
  for j : char := 'A' to jMax do
  for k : integer := 0 to 25 do begin
    M1[i,j,k] := ' ';
    M2[i,j,k] := ' ';
    Mn1[i,j] := ' ';
  end;
  
  for j : char := 'A' to jMax do
    for i : char := 'A' to iMax do 
      if (dataGridView1[ord(i)-ord('A'), ord(j)-ord('A')].Value <> nil) then begin
        M1[j,i,0] := j+i;
        Mn1[j,i] := i;
      end;
      
  for var i : integer := 1 to Decimal.ToInt16(elementCountBox.Value)-1 do
  begin
    RichTextBox1.Text += #13#10 + 'Пути длины ' + i + ':' + #13#10;
    for var j : integer := 0 to 25 do
      if (M1[fromel,toel, j] <> ' ') then RichTextBox1.Text += M1[fromel,toel, j] + #13#10;
    
    composition(iMax);
    
    for var x : char := 'A' to imax do begin
      for var y : char := 'A' to jmax do begin
        for var z : integer := 0 to 25 do begin
          M1[x,y,z] := M2[x,y,z];
          if M1[x,y,z] = '' then M1[x,y,z] := ' ';
          M2[x,y,z] := ' ';
      end; end; end;
  end;
end;

procedure Form1.numericUpDown1_ValueChanged(sender: Object; e: EventArgs);
begin
  fromBox.Maximum := elementCountBox.Value;
  toBox.Maximum := elementCountBox.Value;
  
  // Добавление или удаление столбцов на форму
  if (elementCountBox.Value > dataGridView1.ColumnCount) then begin
    for var i :char := chr(ord('A') + dataGridView1.ColumnCount) 
                    to chr(ord('A') + Decimal.ToInt16(elementCountBox.Value)-1) do begin
      dataGridView1.Columns.Add(columns[i]);
      dataGridView1.Rows.Add();
  end; end
      
  else if (elementCountBox.Value < dataGridView1.ColumnCount) then begin 
    for var i :char := chr(ord('A') + dataGridView1.ColumnCount-1) 
                downto chr(ord('A') + Decimal.ToInt16(elementCountBox.Value)) do begin
      dataGridView1.Columns.Remove(i);
      dataGridView1.Rows.RemoveAt(ord(i)-ord('A'));
      
  end; end;
end;


procedure composition(max : char);
begin
  var lastletter, addletter : char;

  for var i : char := 'A' to max do begin
    for var j : char := 'A' to max do begin
      if M1[i,j,0] <> ' ' then begin //Находим, где есть буквы
        for var k : integer := 0 to 25 do begin
          // Проверяем все возможные комбинации букв
          
          // Берем последнюю букву последовательности и ищем из нее путь
          lastLetter := M1[i,j,k][length(M1[i,j,k])];
          if lastLetter = ' ' then continue;
          for var z : char := 'A' to max do
            if Mn1[lastLetter, z] <> ' ' then begin
              addLetter := Mn1[lastLetter, z];
              
              // Добавляем путь, если он существует
              var l : integer = 0;
              while (M2[i,addLetter,l] <> ' ') and (l < 25) do l += 1;
              M2[i,addLetter,l] := M1[i,j,k] + addLetter;
            end;
          
        end;
      end;
    end;
  end;
  
  deleteNonelementart(max);
end;

procedure deleteNonelementart(max :char);
begin
  for var i : char := 'A' to max do begin
    for var j : char := 'A' to max do begin
        for var k : integer := 0 to 25 do begin
          if M2[i,j,k] <> ' ' then begin
            var letters : array ['A'..'Z'] of integer;
            for var p : char := 'A' to 'Z' do letters[p] := 0;
            
            for var p : integer := 1 to length(M2[i,j,k]) do begin
              letters[M2[i,j,k][p]] += 1;
              
              if letters[M2[i,j,k][p]] > 1 then begin
                M2[i,j,k] := ' ';
                break;
              end;
            end;
          end;
        end;
      end;
    end;
end;

procedure Form1.button2_Click(sender: Object; e: EventArgs);
begin
  RichTextBox1.Text := '';
end;


end.

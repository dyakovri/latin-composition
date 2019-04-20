procedure InitializeComponent;
    begin
        self.elementCountBox := new System.Windows.Forms.NumericUpDown();
        self.label1 := new System.Windows.Forms.Label();
        self.fromBox := new System.Windows.Forms.NumericUpDown();
        self.label2 := new System.Windows.Forms.Label();
        self.toBox := new System.Windows.Forms.NumericUpDown();
        self.label3 := new System.Windows.Forms.Label();
        self.button1 := new System.Windows.Forms.Button();
        self.dataGridView1 := new System.Windows.Forms.DataGridView();
        self.richTextBox1 := new System.Windows.Forms.RichTextBox();
        self.button2 := new System.Windows.Forms.Button();
        (System.ComponentModel.ISupportInitialize(self.elementCountBox)).BeginInit();
        (System.ComponentModel.ISupportInitialize(self.fromBox)).BeginInit();
        (System.ComponentModel.ISupportInitialize(self.toBox)).BeginInit();
        (System.ComponentModel.ISupportInitialize(self.dataGridView1)).BeginInit();
        self.SuspendLayout();
        // 
        // elementCountBox
        // 
        self.elementCountBox.Location := new System.Drawing.Point(528, 25);
        self.elementCountBox.Maximum := new System.Decimal(new System.Int32[4](25, 0, 0, 0));
        self.elementCountBox.Minimum := new System.Decimal(new System.Int32[4](1, 0, 0, 0));
        self.elementCountBox.Name := 'elementCountBox';
        self.elementCountBox.Size := new System.Drawing.Size(92, 20);
        self.elementCountBox.TabIndex := 2;
        self.elementCountBox.Value := new System.Decimal(new System.Int32[4](5, 0, 0, 0));
        self.elementCountBox.ValueChanged += numericUpDown1_ValueChanged;
        // 
        // label1
        // 
        self.label1.ImageAlign := System.Drawing.ContentAlignment.TopRight;
        self.label1.Location := new System.Drawing.Point(369, 23);
        self.label1.Name := 'label1';
        self.label1.Size := new System.Drawing.Size(153, 20);
        self.label1.TabIndex := 2;
        self.label1.Text := 'Количество эл-тов графа:';
        self.label1.TextAlign := System.Drawing.ContentAlignment.MiddleRight;
        // 
        // fromBox
        // 
        self.fromBox.Location := new System.Drawing.Point(528, 67);
        self.fromBox.Maximum := new System.Decimal(new System.Int32[4](5, 0, 0, 0));
        self.fromBox.Minimum := new System.Decimal(new System.Int32[4](1, 0, 0, 0));
        self.fromBox.Name := 'fromBox';
        self.fromBox.Size := new System.Drawing.Size(92, 20);
        self.fromBox.TabIndex := 3;
        self.fromBox.Value := new System.Decimal(new System.Int32[4](1, 0, 0, 0));
        // 
        // label2
        // 
        self.label2.ImageAlign := System.Drawing.ContentAlignment.TopRight;
        self.label2.Location := new System.Drawing.Point(369, 65);
        self.label2.Name := 'label2';
        self.label2.Size := new System.Drawing.Size(153, 20);
        self.label2.TabIndex := 2;
        self.label2.Text := 'От какой вершины путь:';
        self.label2.TextAlign := System.Drawing.ContentAlignment.MiddleRight;
        // 
        // toBox
        // 
        self.toBox.Location := new System.Drawing.Point(528, 92);
        self.toBox.Maximum := new System.Decimal(new System.Int32[4](5, 0, 0, 0));
        self.toBox.Minimum := new System.Decimal(new System.Int32[4](1, 0, 0, 0));
        self.toBox.Name := 'toBox';
        self.toBox.Size := new System.Drawing.Size(92, 20);
        self.toBox.TabIndex := 4;
        self.toBox.Value := new System.Decimal(new System.Int32[4](5, 0, 0, 0));
        // 
        // label3
        // 
        self.label3.ImageAlign := System.Drawing.ContentAlignment.TopRight;
        self.label3.Location := new System.Drawing.Point(369, 90);
        self.label3.Name := 'label3';
        self.label3.Size := new System.Drawing.Size(153, 20);
        self.label3.TabIndex := 2;
        self.label3.Text := 'До какой вершины путь:';
        self.label3.TextAlign := System.Drawing.ContentAlignment.MiddleRight;
        // 
        // button1
        // 
        self.button1.Location := new System.Drawing.Point(528, 130);
        self.button1.Name := 'button1';
        self.button1.Size := new System.Drawing.Size(92, 23);
        self.button1.TabIndex := 5;
        self.button1.Text := 'Найти пути';
        self.button1.UseVisualStyleBackColor := true;
        self.button1.Click += button1_Click;
        // 
        // dataGridView1
        // 
        self.dataGridView1.ColumnHeadersHeightSizeMode := System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
        self.dataGridView1.Location := new System.Drawing.Point(12, 12);
        self.dataGridView1.Name := 'dataGridView1';
        self.dataGridView1.Size := new System.Drawing.Size(351, 351);
        self.dataGridView1.TabIndex := 1;
        // 
        // richTextBox1
        // 
        self.richTextBox1.Location := new System.Drawing.Point(369, 159);
        self.richTextBox1.Name := 'richTextBox1';
        self.richTextBox1.ReadOnly := true;
        self.richTextBox1.Size := new System.Drawing.Size(251, 204);
        self.richTextBox1.TabIndex := 6;
        self.richTextBox1.Text := '';
        // 
        // button2
        // 
        self.button2.DialogResult := System.Windows.Forms.DialogResult.Cancel;
        self.button2.Location := new System.Drawing.Point(430, 130);
        self.button2.Name := 'button2';
        self.button2.Size := new System.Drawing.Size(92, 23);
        self.button2.TabIndex := 6;
        self.button2.Text := 'Очистить';
        self.button2.UseVisualStyleBackColor := true;
        self.button2.Click += button2_Click;
        // 
        // Form1
        // 
        self.AcceptButton := self.button1;
        self.CancelButton := self.button2;
        self.ClientSize := new System.Drawing.Size(632, 375);
        self.Controls.Add(self.richTextBox1);
        self.Controls.Add(self.button2);
        self.Controls.Add(self.button1);
        self.Controls.Add(self.label3);
        self.Controls.Add(self.toBox);
        self.Controls.Add(self.label2);
        self.Controls.Add(self.fromBox);
        self.Controls.Add(self.label1);
        self.Controls.Add(self.elementCountBox);
        self.Controls.Add(self.dataGridView1);
        self.Name := 'Form1';
        self.Text := 'Латинская композиция';
        (System.ComponentModel.ISupportInitialize(self.elementCountBox)).EndInit();
        (System.ComponentModel.ISupportInitialize(self.fromBox)).EndInit();
        (System.ComponentModel.ISupportInitialize(self.toBox)).EndInit();
        (System.ComponentModel.ISupportInitialize(self.dataGridView1)).EndInit();
        self.ResumeLayout(false);
    end;

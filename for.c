using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.OleDb;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace POS_STUDENT
{
    public partial class Form1 : Form
    {
        
            string connectionString = @"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:/DbTest/db.accdb;";

            public Form1()
            {
                InitializeComponent();
            }

            private void btnInsert_Click(object sender, EventArgs e)
            {
                using (OleDbConnection connection = new OleDbConnection(connectionString))
                {
                    string query = "INSERT INTO users (name, phone, email, address) VALUES (?, ?, ?, ?)";
                    using (OleDbCommand command = new OleDbCommand(query, connection))
                    {
                        command.Parameters.AddWithValue("?", txtName.Text);
                        command.Parameters.AddWithValue("?", txtPhone.Text);
                        command.Parameters.AddWithValue("?", txtEmail.Text);
                        command.Parameters.AddWithValue("?", txtAddress.Text);

                        connection.Open();
                        command.ExecuteNonQuery();
                        MessageBox.Show("User added successfully.");
                        LoadData();
                    }
                }
            }

            private void btnLoad_Click(object sender, EventArgs e)
            {
                LoadData();
            }

            private void LoadData()
            {
                using (OleDbConnection connection = new OleDbConnection(connectionString))
                {
                    string query = "SELECT * FROM users";
                    OleDbDataAdapter adapter = new OleDbDataAdapter(query, connection);
                    DataTable table = new DataTable();
                    adapter.Fill(table);
                    dataGridView1.DataSource = table;
                }
            }

            private void btnUpdate_Click(object sender, EventArgs e)
            {
                using (OleDbConnection connection = new OleDbConnection(connectionString))
                {
                    string query = "UPDATE users SET name = ?, phone = ?, email = ?, address = ? WHERE id = ?";
                    using (OleDbCommand command = new OleDbCommand(query, connection))
                    {
                        command.Parameters.AddWithValue("?", txtName.Text);
                        command.Parameters.AddWithValue("?", txtPhone.Text);
                        command.Parameters.AddWithValue("?", txtEmail.Text);
                        command.Parameters.AddWithValue("?", txtAddress.Text);
                        command.Parameters.AddWithValue("?", dataGridView1.SelectedRows[0].Cells["id"].Value);

                        connection.Open();
                        command.ExecuteNonQuery();
                        MessageBox.Show("User updated successfully.");
                        LoadData();
                    }
                }
            }

            private void btnDelete_Click(object sender, EventArgs e)
            {
                using (OleDbConnection connection = new OleDbConnection(connectionString))
                {
                    string query = "DELETE FROM users WHERE id = ?";
                    using (OleDbCommand command = new OleDbCommand(query, connection))
                    {
                        command.Parameters.AddWithValue("?", dataGridView1.SelectedRows[0].Cells["id"].Value);

                        connection.Open();
                        command.ExecuteNonQuery();
                        MessageBox.Show("User deleted successfully.");
                        LoadData();
                    }
                }
            }
        }
    }


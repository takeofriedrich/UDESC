package principal;

import javax.swing.JPanel;
import javax.swing.JTextField;

import arquivosExternos.Entrada;
import classes.Gramatica;

import javax.swing.JButton;
import javax.swing.JOptionPane;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Arquivos extends JPanel {
	private JTextField caminho;
	private Gramatica gramatica = new Gramatica();
	private Entrada editor = new Entrada();

	/**
	 * Create the panel.
	 */
	public Arquivos() {
		
		
		setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBounds(12, 12, 400, 300);
		add(panel);
		panel.setLayout(null);
		
		caminho = new JTextField();
		caminho.setBounds(12, 3, 402, 19);
		panel.add(caminho);
		caminho.setColumns(10);
		caminho.setText("/home/takeofriedrich/Área de Trabalho/gramatica.txt");
		
		JButton carregar = new JButton("carregar arquivo");
		carregar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					editor.leGramaticaT(caminho.getText());
					gramatica = editor.getGramatica();
				} catch (Exception e) {
					JOptionPane.showMessageDialog(null, e.getMessage(),"Erro",JOptionPane.ERROR_MESSAGE);
					e.printStackTrace();
				}
				gramatica = editor.getGramatica();
			}
		});
		carregar.setBounds(235, 34, 154, 25);
		panel.add(carregar);
		
		JButton salvar = new JButton("salvar arquivo");
		salvar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					editor.setGramatica(gramatica);
					editor.gravaGramaticaT(caminho.getText());
				} catch (Exception e) {
					JOptionPane.showMessageDialog(null, e.getMessage(),"Erro",JOptionPane.ERROR_MESSAGE);
				}
			}
		});
		salvar.setBounds(22, 34, 154, 25);
		panel.add(salvar);

	}
}

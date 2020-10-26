package principal;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import sistema.Sistema;

import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.util.LinkedList;
import java.awt.event.ActionEvent;
import javax.swing.JTextPane;
import java.awt.Color;
import javax.swing.JTextArea;
import javax.swing.JComboBox;
import javax.swing.JScrollPane;
import java.awt.Font;

public class Janela extends JFrame {

	private JPanel contentPane;
	private JTextField caminho;
	private Sistema s = new Sistema();
	
	private JTextField palavra;
	
	private final String sI1 = "Etapa 1 - Remove as produções que não levam a um terminal\n";
	private final String sI2 = "Etapa 2 - Remove as produções que não atingem um terminal a partir do simbolo inicial\n";
	private final String sIAll = "Executar - Realiza as etapas 1 e 2 em sequência";
	
	private final String ab1 = "Etapa 1 - Constrói o fechos de todas as variáveis\n";
	private final String abAll = "Executar - Remove as produções na forma variável -> variável\n";
	
	private final String fnc1 = "Etapa 1 - Deixa apenas variáveis no lado direito das produções \n";
	private final String fnc2 = "Etapa 2 - Limita o número de variáveis no lado direito para apenas duas variáveis\n";
	private final String fncAll = "Executar - Realiza as etapas 1 e 2 em sequência";

	private final String infoSimbolosInuteis = "Entre com uma gramática e escolha:\n\n"+sI1+sI2+sIAll;
	private final String infoProducoesVazias = "Entre com uma gramática e remova as produções que levam a ε diretamente ou indiretamente";
	private final String infoProducoesAB = "Entre com uma gramática e escolha:\n\n"+ab1+abAll;
	private final String infoFNC = "Entre com uma gramática e escolha:\n\n"+fnc1+fnc2+fncAll;
	private final String infoEarly = "Entre com uma gramática e com uma palavra a ser reconhecida";
	private final String infoSimb = "Selecione um simbolo, copie e cole onde deseja usá-lo";
	
	private final String dan = "Daniella Vasconcellos - danivasco@msn.com\n";
	private final String takeo = "Vinícius Takeo Friedrich Kuwaki - vtkwki@gmail.com\n";
	private final String disciplina = "Disciplina: Linguagens Formais e Autômatos 2019.2\n";
	private final String ricardo = "Professor: Ricardo F. Martins\n";
	private final String udesc = "UDESC - Universidade do Estado de Santa Catarina\n";
	
	private final String créditos = "Autores:\n"+dan+takeo+"\n"+disciplina+ricardo+udesc;
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Janela frame = new Janela();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public Janela() {
		setTitle("Trabalho de LFA");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setExtendedState(JFrame.MAXIMIZED_BOTH);
		setBounds(0, 0, 2000, 2000);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JPanel arquivo = new JPanel();
		arquivo.setBackground(Color.WHITE);
		arquivo.setBounds(464, 10, 447, 110);
		contentPane.add(arquivo);
		arquivo.setLayout(null);
		
		caminho = new JTextField();
		caminho.setText("");
		caminho.setBounds(12, 35, 423, 19);
		arquivo.add(caminho);
		caminho.setColumns(10);
		
		JLabel lblInformeOCaminho = new JLabel("Informe o caminho:");
		lblInformeOCaminho.setBounds(12, 12, 423, 15);
		arquivo.add(lblInformeOCaminho);
		
		JPanel tela = new JPanel();
		tela.setBounds(12, 0, 440, 693);
		contentPane.add(tela);
		tela.setLayout(null);
		
		JTextPane regras = new JTextPane();
		regras.setBackground(Color.WHITE);
		regras.setBounds(12, 135, 416, 485);
		imprimeTela(regras,s.converteProducoesString());
		tela.add(regras);
		
		JTextPane variaveis = new JTextPane();
		imprimeTela(variaveis,s.converteVariaveisString());
		variaveis.setBounds(12, 28, 416, 25);
		tela.add(variaveis);
		
		JTextPane terminais = new JTextPane();
		imprimeTela(terminais,s.converteTerminaisString());
		terminais.setBounds(12, 82, 416, 25);
		tela.add(terminais);
		
		JScrollPane p2 = new JScrollPane();
		p2.setBounds(464, 326, 361, 300);
		contentPane.add(p2);
		
		JTextPane telaAux = new JTextPane();
		telaAux.setEditable(false);
		p2.setViewportView(telaAux);
		telaAux.setBackground(null);
		telaAux.setText(créditos);
		
		
		JButton carregar = new JButton("carregar o arquivo");
		carregar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					s.leGramaticaArquivo(caminho.getText());
					JOptionPane.showMessageDialog(null, "Gramática lida", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
					imprimeTela(regras,s.converteProducoesString());
					imprimeTela(variaveis,s.converteVariaveisString());
					imprimeTela(terminais,s.converteTerminaisString());
				} catch (Exception e) {
					JOptionPane.showMessageDialog(null, e.getMessage(), "Erro ao ler arquivo", JOptionPane.ERROR_MESSAGE);
				}
				
			}
		});
		carregar.setBounds(22, 63, 188, 25);
		arquivo.add(carregar);
		
		JButton salvar = new JButton("salvar o arquivo");
		salvar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					s.salvaGramaticaArquivo(caminho.getText());
					JOptionPane.showMessageDialog(null, "Gramática salva", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
				} catch (Exception e) {
					JOptionPane.showMessageDialog(null, e.getMessage(), "Erro ao gravar arquivo", JOptionPane.ERROR_MESSAGE);
				}
			}
		});
		salvar.setBounds(235, 63, 188, 25);
		arquivo.add(salvar);
		
		
		JButton carregar2 = new JButton("carregar");
		carregar2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				s.converteStringVariaveis(variaveis.getText());
				s.converteStringTerminais(terminais.getText());
				s.converteStringProducoes(regras.getText());
				JOptionPane.showMessageDialog(null, "Gramática lida", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
			}
		});
		carregar2.setBounds(12, 638, 180, 25);
		tela.add(carregar2);
		
		JButton limpar = new JButton("limpar");
		limpar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				imprimeTela(regras,"");
			}
		});
		limpar.setBounds(241, 638, 187, 25);
		tela.add(limpar);
		
		JLabel lblVariveisDaGramtica = new JLabel("Variáveis da Gramática: ( Simbolo inicial por último )");
		lblVariveisDaGramtica.setBounds(12, 12, 416, 15);
		tela.add(lblVariveisDaGramtica);
		
		JLabel lblTerminaisDaGramtica = new JLabel("Terminais da Gramática:");
		lblTerminaisDaGramtica.setBounds(12, 65, 416, 15);
		tela.add(lblTerminaisDaGramtica);
		
		JLabel lblRegrasDaGramtica = new JLabel("Regras da Gramática:");
		lblRegrasDaGramtica.setBounds(12, 119, 416, 15);
		tela.add(lblRegrasDaGramtica);
		
		JPanel botoes = new JPanel();
		botoes.setBounds(464, 122, 820, 192);
		botoes.setLayout(null);
		contentPane.add(botoes);
		
		JPanel painelSimbolosInuteis = new JPanel();
		painelSimbolosInuteis.setBackground(Color.WHITE);
		painelSimbolosInuteis.setBounds(5, 12, 200, 168);
		botoes.add(painelSimbolosInuteis);
		painelSimbolosInuteis.setLayout(null);
		
		JButton sI2 = new JButton("Etapa 2");
		sI2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					s.simbolosInuteis2();
				} catch (Exception e) {
					JOptionPane.showMessageDialog(null, e.getMessage(), "Erro ao simplificar gramática", JOptionPane.ERROR_MESSAGE);
				}
				imprimeTela(regras,s.converteProducoesString());
				imprimeTela(variaveis,s.converteVariaveisString());
				imprimeTela(terminais,s.converteTerminaisString());
			}
		});
		sI2.setBounds(12, 86, 176, 25);
		painelSimbolosInuteis.add(sI2);
		
		JButton sI1 = new JButton("Etapa 1");
		sI1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					s.simbolosInuteis1();
				} catch (Exception e) {
					JOptionPane.showMessageDialog(null, e.getMessage(), "Erro ao simplificar gramática", JOptionPane.ERROR_MESSAGE);
				}
				imprimeTela(regras,s.converteProducoesString());
				imprimeTela(variaveis,s.converteVariaveisString());
				imprimeTela(terminais,s.converteTerminaisString());
			}
		});
		sI1.setBounds(12, 49, 176, 25);
		painelSimbolosInuteis.add(sI1);
		
		JTextPane txtpnSimbolosInteis = new JTextPane();
		txtpnSimbolosInteis.setEditable(false);
		txtpnSimbolosInteis.setBackground(null);
		txtpnSimbolosInteis.setFont(new Font("Dialog", Font.PLAIN, 14));
		txtpnSimbolosInteis.setText("Simbolos Inúteis");
		txtpnSimbolosInteis.setBounds(31, 12, 142, 25);
		painelSimbolosInuteis.add(txtpnSimbolosInteis);
		
		JButton info1 = new JButton("?");
		info1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				JOptionPane.showMessageDialog(null, infoSimbolosInuteis, "Como funciona", JOptionPane.INFORMATION_MESSAGE);
			}
		});
		info1.setBounds(138, 123, 50, 25);
		painelSimbolosInuteis.add(info1);
		
		JButton sI = new JButton("Executa");
		sI.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					s.simbolosInuteis();
				} catch (Exception e) {
					JOptionPane.showMessageDialog(null, e.getMessage(), "Erro ao simplificar gramática", JOptionPane.ERROR_MESSAGE);
					
				}
				imprimeTela(regras,s.converteProducoesString());
				imprimeTela(variaveis,s.converteVariaveisString());
				imprimeTela(terminais,s.converteTerminaisString());
			}
		});
		sI.setBounds(12, 123, 114, 25);
		painelSimbolosInuteis.add(sI);
		
		JPanel paineProducoesVazias = new JPanel();
		paineProducoesVazias.setBackground(Color.WHITE);
		paineProducoesVazias.setLayout(null);
		paineProducoesVazias.setBounds(208, 12, 200, 168);
		botoes.add(paineProducoesVazias);
		
		JTextPane txtpnProduesVazias = new JTextPane();
		txtpnProduesVazias.setEditable(false);
		txtpnProduesVazias.setText("Produções Vazias");
		txtpnProduesVazias.setFont(new Font("Dialog", Font.PLAIN, 14));
		txtpnProduesVazias.setBackground((Color) null);
		txtpnProduesVazias.setBounds(31, 12, 142, 25);
		paineProducoesVazias.add(txtpnProduesVazias);
		
		JButton info2 = new JButton("?");
		info2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				JOptionPane.showMessageDialog(null, infoProducoesVazias, "Como funciona", JOptionPane.INFORMATION_MESSAGE);
			}
		});
		info2.setBounds(138, 123, 50, 25);
		paineProducoesVazias.add(info2);
		
		JButton pV = new JButton("Executa");
		pV.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					s.producoesVazias();
				} catch (Exception e) {
					JOptionPane.showMessageDialog(null, e.getMessage(), "Erro ao simplificar gramática", JOptionPane.ERROR_MESSAGE);
				}
				imprimeTela(regras,s.converteProducoesString());
				imprimeTela(variaveis,s.converteVariaveisString());
				imprimeTela(terminais,s.converteTerminaisString());
			}
		});
		pV.setBounds(12, 123, 114, 25);
		paineProducoesVazias.add(pV);
		
		JPanel painelProducoesAB = new JPanel();
		painelProducoesAB.setBackground(Color.WHITE);
		painelProducoesAB.setLayout(null);
		painelProducoesAB.setBounds(413, 12, 200, 168);
		botoes.add(painelProducoesAB);
		
		JButton aB1 = new JButton("Etapa 1");
		aB1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				
				s.exclusaoABFechos();
				imprimeTela(telaAux,s.getFechos());
				
			}
		});
		aB1.setBounds(12, 49, 176, 25);
		painelProducoesAB.add(aB1);
		
		JTextPane txtpnProduesAb = new JTextPane();
		txtpnProduesAb.setEditable(false);
		txtpnProduesAb.setText("Produções A->B");
		txtpnProduesAb.setFont(new Font("Dialog", Font.PLAIN, 14));
		txtpnProduesAb.setBackground((Color) null);
		txtpnProduesAb.setBounds(31, 12, 142, 25);
		painelProducoesAB.add(txtpnProduesAb);
		
		JButton info3 = new JButton("?");
		info3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				JOptionPane.showMessageDialog(null, infoProducoesAB, "Como funciona", JOptionPane.INFORMATION_MESSAGE);
			}
		});
		info3.setBounds(138, 123, 50, 25);
		painelProducoesAB.add(info3);
		
		JButton aB = new JButton("Executa");
		aB.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					s.exclusaoAB();
				} catch (Exception e) {
					JOptionPane.showMessageDialog(null, e.getMessage(), "Erro ao simplificar gramática", JOptionPane.ERROR_MESSAGE);
				}
				imprimeTela(regras,s.converteProducoesString());
				imprimeTela(variaveis,s.converteVariaveisString());
				imprimeTela(terminais,s.converteTerminaisString());
			}
		});
		aB.setBounds(12, 123, 114, 25);
		painelProducoesAB.add(aB);
		
		JPanel painelFormaNormalChomsky = new JPanel();
		painelFormaNormalChomsky.setBackground(Color.WHITE);
		painelFormaNormalChomsky.setLayout(null);
		painelFormaNormalChomsky.setBounds(620, 12, 200, 168);
		botoes.add(painelFormaNormalChomsky);
		
		JButton fnc2 = new JButton("Etapa 2");
		fnc2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					s.fnc2();
				} catch (Exception e) {
					JOptionPane.showMessageDialog(null, e.getMessage(), "Erro ao gerar fnc", JOptionPane.ERROR_MESSAGE);
				}
				imprimeTela(regras,s.converteProducoesString());
				imprimeTela(variaveis,s.converteVariaveisString());
				imprimeTela(terminais,s.converteTerminaisString());
			}
		});
		fnc2.setBounds(12, 86, 176, 25);
		painelFormaNormalChomsky.add(fnc2);
		
		JButton fnc1 = new JButton("Etapa 1");
		fnc1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					s.fnc1();
				} catch (Exception e) {
					JOptionPane.showMessageDialog(null, e.getMessage(), "Erro ao gerar fnc", JOptionPane.ERROR_MESSAGE);
				}
				imprimeTela(regras,s.converteProducoesString());
				imprimeTela(variaveis,s.converteVariaveisString());
				imprimeTela(terminais,s.converteTerminaisString());
			}
		});
		fnc1.setBounds(12, 49, 176, 25);
		painelFormaNormalChomsky.add(fnc1);
		
		JTextPane txtpnFormaNormalChomsky = new JTextPane();
		txtpnFormaNormalChomsky.setEditable(false);
		txtpnFormaNormalChomsky.setText("Forma Normal Chomsky");
		txtpnFormaNormalChomsky.setFont(new Font("Dialog", Font.PLAIN, 14));
		txtpnFormaNormalChomsky.setBackground((Color) null);
		txtpnFormaNormalChomsky.setBounds(12, 12, 188, 25);
		painelFormaNormalChomsky.add(txtpnFormaNormalChomsky);
		
		JButton info4 = new JButton("?");
		info4.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				JOptionPane.showMessageDialog(null, infoFNC, "Como funciona", JOptionPane.INFORMATION_MESSAGE);
			}
		});
		info4.setBounds(138, 123, 50, 25);
		painelFormaNormalChomsky.add(info4);
		
		JButton fnc = new JButton("Executa");
		fnc.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					s.fnc();
				} catch (Exception e) {
					JOptionPane.showMessageDialog(null, e.getMessage(), "Erro ao gerar fnc", JOptionPane.ERROR_MESSAGE);
				}
				imprimeTela(regras,s.converteProducoesString());
				imprimeTela(variaveis,s.converteVariaveisString());
				imprimeTela(terminais,s.converteTerminaisString());
			}
		});
		fnc.setBounds(12, 123, 114, 25);
		painelFormaNormalChomsky.add(fnc);
		
		JPanel painelSimbolosEspeciais = new JPanel();
		painelSimbolosEspeciais.setBackground(Color.WHITE);
		painelSimbolosEspeciais.setBounds(923, 10, 361, 110);
		contentPane.add(painelSimbolosEspeciais);
		painelSimbolosEspeciais.setLayout(null);
		
		LinkedList<String> simbolos = new LinkedList<String>();
		simbolos.add("ε");
		simbolos.add("δ");
		
		JComboBox caixaSimbolos = new JComboBox();
		caixaSimbolos.setBounds(12, 12, 337, 24);
		painelSimbolosEspeciais.add(caixaSimbolos);
		
		caixaSimbolos.addItem("Selecione um simbolo");
		for(int i=0;i<simbolos.size();i++) {
			caixaSimbolos.addItem(simbolos.get(i));
		}
		
		JTextPane textPane = new JTextPane();
		textPane.setEditable(false);
		textPane.setBackground(Color.WHITE);
		textPane.setBounds(12, 44, 160, 24);
		painelSimbolosEspeciais.add(textPane);
		
		JButton select = new JButton("Selecionar");
		select.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if(caixaSimbolos.getSelectedIndex()!=0) {
					textPane.setText(String.valueOf(caixaSimbolos.getSelectedItem()));
				}else {
					textPane.setText("");
				}
			}
		});
		select.setBounds(184, 44, 165, 25);
		painelSimbolosEspeciais.add(select);
		
		JButton infoSimbolos = new JButton("?");
		infoSimbolos.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				JOptionPane.showMessageDialog(null, infoSimb, "Como funciona", JOptionPane.INFORMATION_MESSAGE);
			}
		});
		infoSimbolos.setBounds(12, 73, 50, 25);
		painelSimbolosEspeciais.add(infoSimbolos);
		
		JButton limparEarly = new JButton("Limpar");
		limparEarly.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				telaAux.setBackground(null);
				telaAux.setText("");
			}
		});
		limparEarly.setBounds(464, 638, 162, 25);
		contentPane.add(limparEarly);
		
		JPanel painelearly = new JPanel();
		painelearly.setBackground(Color.WHITE);
		painelearly.setBounds(923, 326, 282, 139);
		contentPane.add(painelearly);
		painelearly.setLayout(null);
		
		JPanel painelPalavra = new JPanel();
		painelPalavra.setBackground(Color.WHITE);
		painelPalavra.setBounds(12, 12, 261, 63);
		painelearly.add(painelPalavra);
		painelPalavra.setLayout(null);
		
		JLabel lblDigiteAPalavra = new JLabel("Digite a palavra a ser reconhecida:");
		lblDigiteAPalavra.setBounds(12, 12, 237, 15);
		painelPalavra.add(lblDigiteAPalavra);
		
		palavra = new JTextField();
		palavra.setBounds(12, 32, 237, 19);
		painelPalavra.add(palavra);
		palavra.setColumns(10);
		
		JButton early = new JButton("Reconhecer");
		early.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				s.setPalavra(palavra.getText());
				try {
					if(s.earlyReconheceu()) {
						JOptionPane.showMessageDialog(null, "Palavra reconhecida pela gramática", "Algoritmo de Early", JOptionPane.INFORMATION_MESSAGE);
					}else {
						JOptionPane.showMessageDialog(null, "Palavra não reconhecida pela gramática", "Algoritmo de Early", JOptionPane.ERROR_MESSAGE);
					}
				} catch (Exception e) {
					JOptionPane.showMessageDialog(null, e.getMessage(), "Erro ao reconhecer palavra", JOptionPane.ERROR_MESSAGE);
				}
			}
		});
		early.setBounds(12, 87, 190, 25);
		painelearly.add(early);
		
		JButton info5 = new JButton("?");
		info5.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				JOptionPane.showMessageDialog(null, infoEarly, "Como funciona", JOptionPane.INFORMATION_MESSAGE);
			}
		});
		info5.setBounds(214, 87, 50, 25);
		painelearly.add(info5);
		
		JPanel panel_5 = new JPanel();
		panel_5.setBounds(837, 480, 447, 181);
		contentPane.add(panel_5);
		panel_5.setLayout(null);
		
		JTextPane txtpnAutores = new JTextPane();
		txtpnAutores.setBackground(null);
		txtpnAutores.setBounds(0, 0, 447, 181);
		panel_5.add(txtpnAutores);
		
		JButton btnCrditos = new JButton("Créditos");
		btnCrditos.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				telaAux.setText(créditos);
			}
		});
		btnCrditos.setBounds(663, 638, 162, 25);
		contentPane.add(btnCrditos);
		
	}
	
	public void imprimeTela(JTextPane painel, String texto) {
		painel.setText(texto);
	}
	
	public void imprimeTela(JTextArea painel, String texto) {
		painel.setText(texto);
	}
}

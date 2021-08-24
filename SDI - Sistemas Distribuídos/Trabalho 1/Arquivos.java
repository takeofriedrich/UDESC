import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.Files;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;

public class Arquivos {

    public byte[] readBytesFromFile(String path) throws IOException {
        File file = new File(path);
        return Files.readAllBytes(file.toPath());
    }

    public void writeBytesInFile(String path, byte[] bytes, boolean append) throws IOException {
        File file = new File(path);
        if (!file.exists()) {
            file.createNewFile();
        }
        FileOutputStream outputStream = new FileOutputStream(file, append);
        outputStream.write(bytes);
        outputStream.close();
    }

    // Este metodo terminou sendo inutil devido a que o getContador() também retorna
    // Int
    public int getContador(String nome, int cliente) throws IOException {
        Map<String, Integer> dados = parseCSV(cliente);

        // Se entra no if também tem que incrementar o contador

        if (dados.containsKey(nome)) {
            return dados.get(nome);
        } else {
            incrementaContador(nome, cliente);
        }
        return 0;
    }

    private void writeCSV(Map<String, Integer> dados, int cliente) throws IOException {
        String file = "";
        for (String key : dados.keySet()) {
            file += key + "," + dados.get(key) + "\n";
        }
        writeBytesInFile("contador" + cliente + ".csv", file.getBytes(), false);
    }

    private Map<String, Integer> parseCSV(int cliente) throws IOException {
        File file = new File("contador" + cliente + ".csv");
        Map<String, Integer> csv = new HashMap<String, Integer>();
        String linhas = new String(Files.readAllBytes(file.toPath()));
        if (linhas.isEmpty()) {
            return csv;
        }
        String[] usuarios = linhas.split("\n");
        for (String linha : usuarios) {
            String[] infos = linha.split(",");
            csv.put(infos[0], Integer.parseInt(infos[1]));
        }
        return csv;
    }

    /*
     * 0 -> servidor 1 -> cliente1 2 -> cliente2 3 -> cliente3
     */
    public int incrementaContador(String nome, int cliente) throws IOException {
        Map<String, Integer> mapa = parseCSV(cliente);
        if (mapa.containsKey(nome)) {
            mapa.replace(nome, mapa.get(nome) + 1);
        } else {
            mapa.put(nome, 0);
        }
        writeCSV(mapa, cliente);
        return mapa.get(nome);
    }

}

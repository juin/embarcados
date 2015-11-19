package br.edu.ifba.embarcados.javaapp.asincexec;

public interface IListenerAcelerometro {
	
	public void notificarDados(float altitude, char queda);
	public void notificarAltitude(float altitude);
	public void notificarQueda(char queda);
	
}

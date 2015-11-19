package br.edu.ifba.embarcados.javaapp.asincexec;

public interface IListenerAcelerometro {
	
	public void notificarDados(float altitude, int queda);
	public void notificarAltitude(float altitude);
	public void notificarQueda(int queda);
	
}

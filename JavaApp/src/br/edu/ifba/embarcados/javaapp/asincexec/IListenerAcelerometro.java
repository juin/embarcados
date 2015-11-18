package br.edu.ifba.embarcados.javaapp.asincexec;

public interface IListenerAcelerometro {
	
	public void notificarAltitude(float altitude);
	public void notificarQueda(char queda);
	
}

package br.edu.ifba.embarcados.javaapp.asincexec;

public interface IListenerAcelerometro {
	
	public void notificarMovimento(int x, int y, int z);
	public void notificarVibracao();
	
}

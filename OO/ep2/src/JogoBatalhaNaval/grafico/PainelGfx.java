package JogoBatalhaNaval.grafico;

import java.awt.Color;
import java.awt.Graphics;

import JogoBatalhaNaval.Check.Botao;
import JogoBatalhaNaval.Player.Mana;

public class PainelGfx {
	public static void desenhaPainel(Graphics grafico) {
		if(!Botao.getBotaotiroSimplesPress()) {
			grafico.drawImage(Assets.tiroSimples,764, 30,null);
		}else {
			grafico.drawImage(Assets.tiroSimplesPress,764, 30,null);
		}
				
		if(!Botao.getBotaotiroLinhaPress()) {
			grafico.drawImage(Assets.tiroLinha,826,30,null);
		}else {
			grafico.drawImage(Assets.tiroLinhaPress,826,30,null);
		}
		if(!Botao.getBotaoRadar2x2Press()) {
			grafico.drawImage(Assets.radar2x2,764,92,null);
		}else {
			grafico.drawImage(Assets.radar2x2Press,764,92,null);
		}
		if(!Botao.getBotaoTiro2x2Press()) {
			grafico.drawImage(Assets.botaoTiro2x2,826,92,null);
		}else {
			grafico.drawImage(Assets.botaoTiro2x2Press,826,92,null);
		}
		grafico.setColor(Color.black);
		grafico.fillRect(764,15, 70, 10);
		grafico.setColor(Color.WHITE);
		grafico.drawString("Mana: " + Integer.toString(Mana.getMana()), 765, 25);
	}
}

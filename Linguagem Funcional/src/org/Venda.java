package src.org;

public class Venda {
    private String produto;
    private String categoria;
    private int quantidade;
    private double precoUnitario;
    private String vendedor;

    public Venda(String produto, String categoria, int quantidade, double precoUnitario, String vendedor) {
        this.produto = produto;
        this.categoria = categoria;
        this.quantidade = quantidade;
        this.precoUnitario = precoUnitario;
        this.vendedor = vendedor;
    }

    public String getProduto() {
        return produto;
    }

    public String getCategoria() {
        return categoria;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public double getPrecoUnitario() {
        return precoUnitario;
    }

    public String getVendedor() {
        return vendedor;
    }

    public double getTotal() {
        return quantidade * precoUnitario;
    }

    @Override
    public String toString() {
        return produto + " | " + categoria + " | qtd: " + quantidade + " | preço: " + precoUnitario + " | vendedor: "
                + vendedor + " | total: " + getTotal();
    }
}

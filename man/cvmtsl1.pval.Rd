\name{cvmtsl1.pval}
\alias{cvmtsl1.pval}
\title{Computing Exact P-value for L1-version of Cramer-von Mises Two Sample Tests}
\description{
The L1-version of Cramer-von Mises two sample test is to test
whether two independent samples were drawn from the same 
population. The function cvmtsl1.pval() evaluates the p-value
for computed test score(s).
}
\usage{
cvmtsl1.pval(cvmstats, m, n)
}
\arguments{
  \item{cvmstats}{an R object holding a list of computed Cramer-von Mises
                  test scores.}
  \item{m}{sample size of the first sample.}
  \item{n}{sample size of the second sample.}
}
\value{The returned value the p-value(s)}
\references{Yuanhui Xiao, Alexander Gordon, and Andrew Yakovlev (2006), 
The L1-version of the Cramer-von Mises Test for Two-Sample Comparisons
in Microarray Data Analysis, EURASIP Journal on Bioinformatics and
System Biology, Volume (2006), Article ID 85769, Pages 1-9, 
DOI 10.1155/BSB/2006/85769
}
\note{
The function cvmtsl1.pval() first construct the distribution
function. This process may be slow, if the sample sizes are large. 
Once the distribution function is established, 
the function us convolution operation to compute the p-value(s) for given
Cramer-von Mises test statistics. So, if you have a sequence of pairs
of samples of the same sample sizes n and m, it is best to compute
the test scores for all pairs of samples, and then call this function. 
If you compute the p-values seperately, the process may be slow.
}
\author{
Yuanhui Xiao and Ye Cui, Department of Mathematics and Statistics, 
Georgia State University, Atlanta, Georgia, 30302
\email{matyxx@langate.gsu.edu}
}
\seealso{cvmtsl1.test}
\examples{

## sample size of the first sample
n <- 10

## create a sample x of size n from the normal distribution with mean 0 and 
## standard deviation 1
x <- rnorm(n, 0, 1)

## sample size of the second sample
m <- 10

## create a sample y of size m from the normal distribution with mean 1 and
## standard deviation 1
y <- rnorm(m, 1, 1)

## compute the Cramer-von Mises test statistic
 cvm <- cvmtsl1.test(x, y)

## compute the p-value for the test.
 pval <- cvmtsl1.pval(cvm, n, m)

## Now suppose x is a list of samples of the same size (n), and y is a list 
##   of samples of the same size (m),  and you want to test whether each pair
##   (x[i], y[i]) were drawn from the same population, for i = 1, 2, ...

## The following way to use cvmtsl1.pval() is not recommanded

##   for(i <- 1; i<=length(x); i++){

##      cvm  <- cvmtsl1.test(x[i], y[i])
##      pval <- cvmtsl1.pval(cvm, n, m)
##   }

## Why? In each call to the function cvmts.pval(), in the first step established is 
## the distribution of the Cramer-von Mises test statistics under the 
## assumption that the two sample were drawn from the same population. Then 
## the distribution is used to calculate the p-value. The first step may
## be expensive if the sample sizes n and m are large. 
   
## I prefer the following way

##  initialize   
#    cvms <- seq(1, length(x)) 

##  compute test scores
#   for(i <- 1; i<=length(x); i++){
#     cvms[i] <- cvmtsl1.test(x[i], y[i])
#   }

#   compute p-values
#    pvals <- cvmtsl1.pval(cvms, n, m)
}
\keyword{nonparametric}

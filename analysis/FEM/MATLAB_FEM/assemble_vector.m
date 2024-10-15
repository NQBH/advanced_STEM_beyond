function b = assemble_vector(str_integrand_test, str_cofvar, mesh_geo, degree_FE, number)
% Assembly the finite-element right hand side vector
% Author: Nguyen Quan Ba Hong
% Date: 15/10/2018
% Last Update: 6/11/2018
% Inputs:
% + str_integrand_test: character string identifying the operator B
% + str_cofvar: character string identifying the function alpha(x)
% + mesh_geo: a mesh structure defining the geometry, if degree_FE = 1,
% this mesh structure must be a P_1 mesh structure, if degree_FE = 2, it
% must be modified into a P_2 mesh structure, before running this script
% + degree_FE: degree of the finite-element interpolation
% + number: identification number of the quadrature formula
% Output:
% + assemble_vector: assembled finite-element RHS vector

%% Points & Weights of Quadrature Formulas for the Reference Element
[points, weights] = quadrature(number); % Nodal Quadrature Formulas
% [points, weights] = Gaussian_quadrature(4); % Gaussian Quadrature Fofmulas

%% Main Loops
b = zeros(size(mesh_geo.coords,1),1); % Initialize
for K = 1:size(mesh_geo.triangles,1) % Loop on All Triangles of the Mesh Given
    % Coordinates of Vertices of the K-th Triangle in the Mesh
    % the Vertices in P_K of this Triangle
    vertices = mesh_geo.coords(mesh_geo.triangles(K,:),:); 
    main_vertices = vertices([1,2,3],:); % the Vertices in P_1 of this Triangle
    for q = 1:size(points,1) % Loop on All Quadrature Points
        % Evaluate the Nodal Basis Functions of the Reference Element at 
        % the Quadrature Points
        [vals_hatphi, dervals_hatphi] = shape_fcts(points(q,:), degree_FE);
        % Evaluate the Geometric Basis Functions at the Quadrature Points
        [vals_hatpsi, dervals_hatpsi] = shape_fcts(points(q,:), 1); %P_1 Isoparametric
        % Evaluate the Geometric Function at the Quadrature Point
        geo_func = [dot(vals_hatpsi, main_vertices(:,1)), ...
            dot(vals_hatpsi, main_vertices(:,2))];
        % Evaluate the Jacobian Matrix of the Geometric Function at the 
        % Quadrature Point
        jacob = compute_jacobian(main_vertices, dervals_hatpsi);
        % Compute the Gradient of the Function phi(x)
        dervals_phi = dervals_hatphi/jacob;
        for i = 1:size(mesh_geo.triangles,2) % Loop on the Node i of the Element K
            % Global Index of the Node i of the Element K
            I = mesh_geo.triangles(K, i); 
            % Add Contribution of (i,j) at the Quadrature Point
            b(I) = b(I) + weights(q)*feval(str_cofvar, geo_func)*...
                diff_op(str_integrand_test, vals_hatphi(i), dervals_phi(i,:))...
                *abs(det(jacob));
        end
    end
end
